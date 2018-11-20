/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 16:07:22 by fablin      ###    #+. /#+    ###.fr     */
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

	if ((args = ft_strsplit(line, SEPARATOR_CHAR)) == NULL)
	{
		ft_exit_asm("Invalid args\n");
	}
	tmp_split = ft_strsplit_whitespace(args[0]);
	arg1 = ft_strdup(tmp_split[count_split(tmp_split) - 1]);
	arg2 = ft_strdup(args[1]);
	arg3 = ft_strdup(args[2]);
	freesplit(&tmp_split);
	freesplit(&args);
	if ((args = (char **)malloc(4 * sizeof(char *))))
	{
		ft_bzero((int *)args, 4);
		args[0] = arg1;
		args[1] = arg2;
		args[2] = arg3;
	}
	return (args);
}

void	lexer(int fd)
{
	int		gnl;
	char	*line;
	char	*label = NULL;
	char	**split = NULL;
	char	*opcode = NULL;
	int		line_n;
	t_op	*op = NULL;


	line = NULL;
	line_n = 1;
	while((gnl = get_next_line(fd, &line)) > 0)
	{
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
		op = get_op(opcode);
		if (!op)
		{
			ft_printfd(STDERR, "Unknown operation on line %d: '%s'\n",line_n, line);
			ft_exit_asm(NULL);
		}

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
