/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 22:14:34 by fablin      ###    #+. /#+    ###.fr     */
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


void	trim_whitespace(char **str)
{
	char	*start;
	char	*end;
	char	*trim;
	
	if (!str || !*str)
		return ;
	start = *str;
	while(*start && ft_iswhitespace(*start))
		start++;
	end = &start[ft_strlen(start)];
	while(end > start && ft_iswhitespace(*end))
		end--;
	if (start != *str || end != &str[0][ft_strlen(*str) - 1])
	{
		trim = ft_strsub(*str, start - *str, end - start);
		ft_strdel(str);
		*str = trim;
	}
}

void	lexer(int fd)
{
	int		gnl;
	char	*line;
	int		i;
	char	*label = NULL;
	char	**split = NULL;
	char	*opcode = NULL;
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
		// params = registre(r1..rx) ou direct(DIRECT_CHAR %) ou indirect() ou label

		// recup du label et de l'opcode
		trim_whitespace(&line);
		if ((split = ft_strsplit_whitespace(line)) == NULL)
		{
			ft_exit_asm("Empty line\n");
		}
		if (split[0] && split[0][ft_strlen(split[0]) - 1] == LABEL_CHAR) // si split[i]=="LABEL_CHARS:"
		{
			label = ft_strdup(split[0]);
			opcode = ft_strdup(split[1]);
		}
		else
			opcode = ft_strdup(split[0]);
		freesplit(&split);
		

		
		
		// boucle sur l'op_tab pour trouver l'opcode d'indice i
		i = 0;
		while (i < REG_NUMBER)
		{
			if (!ft_strcmp(opcode, g_env.op_tab[i].op))
			{
				op = &g_env.op_tab[i];
				break; // op est trouvé
			}
			i++;
		}
		if (i == REG_NUMBER || !op) // si la boucle ne trouve pas l'opcode
		{
			ft_printfd(STDERR, "Unknown operation on line %d: '%s'\n",line_n, line);
			ft_exit_asm(NULL);
		}



		//maintenant que op est defini, on peut verifier le nombre d'args pour cet op
		if ((split = ft_strsplit(line, SEPARATOR_CHAR)) == NULL)
		{
			ft_exit_asm("Invalid args\n");
		}
		// tmp_split sert a gerer le premier arg qui est un cas particulier car split[0]==:lab op arg1, split[1]=arg2 et split[2]=arg2
		char **tmp_split = ft_strsplit_whitespace(split[0]);
		char *arg1 = ft_strdup(tmp_split[count_split(tmp_split) - 1]);
		char *arg2 = ft_strdup(split[1]);
		char *arg3 = ft_strdup(split[2]);
		freesplit(&tmp_split);
		freesplit(&split);
		split = (char **)malloc(4 * sizeof(char *));
		ft_bzero((int *)split, 4);
		split[0] = arg1;
		split[1] = arg2;
		split[2] = arg3;
		i = 0;
		int nb_arg = count_split(split);
		if (op->nb_arg != nb_arg)
		{
			if (op->nb_arg > nb_arg)
				ft_printfd(STDERR, "Not enough arguments for '%s' on line %d: '%s'\n",op->op, line_n, line);
			else
				ft_printfd(STDERR, "Too many arguments for '%s' on line %d: '%s'\n",op->op, line_n, line);
			ft_exit_asm(NULL);
		}
		
		// on a le bon nombre d'args, donc on verifie les types (T_REG, T_DIR, T_IND, T_LAB)
		// args = registre(r1..rREG_NUMBER) ou direct(DIRECT_CHAR %) ou indirect()
		int type;
		i = 0;
		while (i < nb_arg)
		{
			trim_whitespace(&split[i]);
			type = 0;
			type += is_t_reg(split[i], op->args[i]);
			type += is_t_dir(split[i], op->args[i]);
			type += is_t_ind(split[i], op->args[i]);
			type += is_t_lab(split[i], op->args[i]);
			if (type != 1)
			{
				ft_printf("type=%d\n",type);
				ft_printfd(STDERR, "Invalid arguments on line %d: '%s'\n",line_n, line);
				ft_exit_asm(NULL);
			}
			i++;
		}
		line_n++;
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
