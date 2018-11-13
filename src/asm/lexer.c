/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:09:26 by fablin      ###    #+. /#+    ###.fr     */
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
		if ((split = ft_strsplit(ft_strtrim(line), ' ')) == NULL)
			ft_exit_asm("Empty line\n");

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
			ft_printf("comparing %s and %s\n", g_env.op_tab[i].op, opcode);
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
	}
	ft_strdel(&line);

	//maintenant que op est defini, on peut verifier le nombre d'args pour cet op
	split = ft_strsplit(ft_strtrim(params), ',');
	int nb_arg = count_split(split);
	if (op->nb_arg != nb_arg)
	{
		if (op->nb_arg > nb_arg)
			ft_printfd(STDERR, "Not enough arguments for %s on line %d: %s\n",op->op, line_n, line);
		else
			ft_printfd(STDERR, "Too many arguments for %s on line %d: %s\n",op->op, line_n, line);
		ft_exit_asm(NULL);
	}
	
	// on a le bon nombre d'args, donc on verifie les types (T_REG, T_DIR, T_IND, T_LAB)
	i = 0;
	while (i < op->nb_arg)
	{
		if (1)
		{;}
		i++;
	}
	
	if (gnl == -1 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}

	//repositionnement de la tête de lecture au debut du fichier
	lseek(fd, 0, SEEK_SET);
}
