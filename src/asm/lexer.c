/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 19:07:12 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

/* exemple de compilation :
.name "zork"
.comment "just a basic living prog"
l2: sti r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %:live
# Executable compile:
#
# 0x0b,0x68,0x01,0x00,0x0f,0x00,0x01
# 0x06,0x64,0x01,0x00,0x00,0x00,0x00,0x01
# 0x01,0x00,0x00,0x00,0x01
# 0x09,0xff,0xfb
*/

int		count_split(char **split)
{
	int count = 0;
	while (split && *split)
	{
		count++;
		split++;
	}
	return (count);
}

// verif du formatage des labels ":LABEL_CHARS"
int		is_label_str(char *str)
{
	if (str[0]++ != LABEL_CHAR)
		return (0);
	while (*str)
	{
		if (!ft_strchr(LABEL_CHARS, (int)str))
			return (0);
		str++;
	}
	return(1);
}

void	lexer(int fd)
{
	int		gnl;
	char	*line;
	int		i;
	char	*label;
	char	**split;
	char	*opcode;
	char	*params;
	int		line_n;
	t_op	*op = NULL;
	char	*trim;


	line = NULL;
	line_n = 1;
	while((gnl = get_next_line(fd, &line)) > 0)
	{
		// chaque ligne/instruction est composée d'un label, d'un opcode et des paramètres
		// attention aux commentaires
		// label = LABEL_CHARS
		// opcode = g_env.op_tab[x][0]
		// params = registre(r1..rx) ou direct(DIRECT_CHAR %) ou indirect()

		// recup des elements de la ligne
		trim = ft_strtrim(line);
		if ((split = ft_strsplit(trim, ' ')) == NULL)
		{
			ft_strdel(&trim);
			ft_exit_asm("Empty line\n");
		}
		ft_strdel(&trim);
		
		if (split[0] && split[1] && split[2])
		{
			label = split[0];
			opcode = split[1];
			params = split[2];
		}
		else if (split[0] && split[1])
		{
			opcode = split[0];
			params = split[1];
		}
		else
		{
			ft_printfd(STDERR, "Invalid syntax on line %d: %s\n",line_n, line);
			ft_exit_asm(NULL);
		}

		// boucle sur l'op_tab pour trouver l'opcode d'indice i
		i = 0;
		while (i < REG_NUMBER)
		{
			if (ft_strstr(opcode, g_env.op_tab[i].op))
			{
				op = &g_env.op_tab[i];
				break; // op est trouvé
			}
			i++;
		}
		if (i == REG_NUMBER) // si la boucle ne trouve pas l'opcode
		{
			ft_printfd(STDERR, "Invalid label on line %d: %s\n",line_n, line);
			ft_exit_asm(NULL);
		}
		line_n++;

		//maintenant que op est defini, on peut verifier le nombre d'args pour cet op
		trim = ft_strtrim(params);
		split = ft_strsplit(trim, ',');
		int nb_arg = count_split(split);
		if (op->nb_arg != nb_arg)
		{
			if (op->nb_arg > nb_arg)
				ft_printfd(STDERR, "Not enough arguments for %s on line %d: %s\n",op->op, line_n, line);
			else
				ft_printfd(STDERR, "Too many arguments for %s on line %d: %s\n",op->op, line_n, line);
			ft_strdel(&trim);
			ft_exit_asm(NULL);
		}
		ft_strdel(&trim);
		
		// on a le bon nombre d'args, donc on verifie les types (T_REG, T_DIR, T_IND, T_LAB)
		// args = registre(r1..rREG_NUMBER) ou direct(DIRECT_CHAR %) ou indirect()
		i = 0;
		while (i < nb_arg)
		{
			if (op->args[i] % T_REG == 0) // registre est r1...rx
			{
				if (split[i][0] != 'r' || !ft_isdigit(split[i][1]))
				{
					ft_printfd(STDERR, "Invalid argument on line %d: %s\nRegister expected but '%s' given\n",line_n, line, split[i]);
					ft_exit_asm(NULL);
				}
			}
			else if (op->args[i] % T_DIR == 0) // direct est %0-x ou %:LABEL_CHARS
			{
				if (split[i][0] != DIRECT_CHAR || (!ft_isdigit(split[i][1]) && !is_label_str(&split[i][1])))
				{
					ft_printfd(STDERR, "Invalid argument on line %d: %s\nDirect expected but '%s' given\n",line_n, line, split[i]);
					ft_exit_asm(NULL);
				}
			}
			else if (op->args[i] % T_IND == 0) // indirect comme direct mais sans %
			{
				if(!ft_isdigit(split[i][0]) && !is_label_str(&split[i][0]))
				{
					ft_printfd(STDERR, "Invalid argument on line %d: %s\nIndirect expected but '%s' given\n",line_n, line, split[i]);
					ft_exit_asm(NULL);
				}
			}
			else if (op->args[i] % T_LAB == 0) // label coomence avec :
			{
				if (!is_label_str(&split[i][0]))
				{
					ft_printfd(STDERR, "Invalid argument on line %d: %s\nLabel expected but '%s' given\n",line_n, line, split[i]);
					ft_exit_asm(NULL);
				}
			}
			i++;
		}
		// quoi d'autre?
	}
	ft_strdel(&line);
	
	if (gnl == -1 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}

	//repositionnement de la tête de lecture au debut du fichier
	lseek(fd, 0, SEEK_SET);
}
