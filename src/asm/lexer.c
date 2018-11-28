/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 17:24:38 by fablin      ###    #+. /#+    ###.fr     */
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

int		check_arg_type(char **args, t_op *op)
{
	int i;
	int type;
	int nb_arg = count_split(args);

	i = 0;
	while (i < nb_arg)
	{
		trim_whitespace(&args[i]);
		type = 0;
		type += is_t_reg(args[i], op->args[i]);
		type += is_t_dir(args[i], op->args[i]);
		type += is_t_ind(args[i], op->args[i]);
		type += is_t_lab(args[i], op->args[i]);
		if (type != 1)
			return (type);
		i++;
	}
	return (1);
}

char **get_args(char *line)
{
	char **tmp_split;
	char **args;
	char *arg1;
	char *arg2;
	char *arg3;


	tmp_split = NULL;
	args = NULL;
	arg1 = NULL;
	arg2 = NULL;
	arg3 = NULL;
	if ((args = ft_strsplit(line, SEPARATOR_CHAR)) == NULL)
	{
		ft_exit_asm("Invalid args\n");
	}
	
	tmp_split = ft_strsplit_whitespace(args[0]);
	arg1 = ft_strdup(tmp_split[count_split(tmp_split) - 1]);
	freesplit(&tmp_split);
	
	if (args[1])
		arg2 = ft_strdup(args[1]);
	if (args[1] && args[2])
		arg3 = ft_strdup(args[2]);
	
	freesplit(&args);
	if ((args = (char **)malloc(4 * sizeof(char *))))
	{
		ft_bzero((void *)args, 4);
		args[0] = arg1;
		args[1] = arg2;
		args[2] = arg3;
		args[3] = NULL;
	}
	return (args);
}

void	lexer(int fd)
{
	int		gnl;
	char	*line = NULL;
	char	*label = NULL;
	char	**split = NULL;
	char	*opcode = NULL;
	int		line_n;
	t_op	*op = NULL;
	int		name = 0;
	int		comment = 0;


	line = NULL;
	line_n = 1;
	while((gnl = get_next_line(fd, &line)) > 0)
	{
		trim_whitespace(&line);
		if (ft_strlen(line) == 0)
		{
			ft_strdel(&line);
			continue;
		}
		// gestion des commentaires
		if (!(split = ft_strsplit(line, '#')))
		{
			ft_printfd(STDERR, "Comment error on line %d: '%s'\n",line_n, line);
			ft_exit_asm(NULL);
		}
		ft_strdel(&line);
		line = ft_strdup(split[0]);
		freesplit(&split);
		

		if (!name || !comment)
		{
			if (ft_strstr(line, ".name"))
			{
				if (!(ft_strchr(line, '"') < ft_strrchr(line, '"')))
					ft_exit_asm("Header name syntax error.\n");
				name = 1;
			}
			if (ft_strstr(line, ".comment"))
			{
				if (!(ft_strchr(line, '"') < ft_strrchr(line, '"')))
					ft_exit_asm("Header comment syntax error.\n");
				comment = 1;
			}
		}
		else
		{
		if ((split = ft_strsplit_whitespace(line)) == NULL)
			ft_exit_asm("Error\n");
		if (split[0] && split[0][ft_strlen(split[0]) - 1] == LABEL_CHAR) // si split[0]=="LABEL_CHARS:"
		{
			label = ft_strdup(split[0]);
			opcode = ft_strdup(split[1]);
		}
		else
			opcode = ft_strdup(split[0]);
		freesplit(&split);
		if (!(op = get_op(opcode)))
		{
			ft_printfd(STDERR, "Unknown operation on line %d: '%s'\n",line_n, line);
			ft_exit_asm(NULL);
		}
		ft_strdel(&opcode);
		ft_strdel(&label);
		
		char **args = get_args(line);
		int nb_arg = count_split(args);
		if (op->nb_arg != nb_arg)
		{
			if (op->nb_arg > nb_arg)
				ft_printfd(STDERR, "Not enough arguments for '%s' on line %d: '%s'\n",op->op, line_n, line);
			else
				ft_printfd(STDERR, "Too many arguments for '%s' on line %d: '%s'\n",op->op, line_n, line);
			ft_exit_asm(NULL);
		}

		if (check_arg_type(args, op) != 1)
		{
			ft_printfd(STDERR, "Invalid arguments on line %d: '%s'\n",line_n, line);
			ft_exit_asm(NULL);
		}
		ft_strdel(&args[0]);
		ft_strdel(&args[1]);
		ft_strdel(&args[2]);
		ft_strdel(&args[3]);
		free(args);
		}
		ft_strdel(&line);
		line_n++;
	}
	ft_strdel(&line);
	
	if (gnl == 0 && !(name && comment))
		ft_exit_asm("Missing header.\n");
	
	if (gnl == -1 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}

	//repositionnement de la tête de lecture au debut du fichier
	ft_printf("Fichier valide.\n");
	lseek(fd, 0, SEEK_SET);
}
