/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 14:06:33 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_label	*get_label(char *label_name, t_list **labels)
{
	t_label	*label;
	t_list	*lst;

	label = NULL;
	lst = *labels;
	while (lst)
	{
		if (!ft_strcmp(((t_label *)lst->content)->name, label_name))
			label = (t_label *)lst->content;
		lst = lst->next;
	}
	if (!label)
	{
		label = new_label(ft_strdup(label_name), 0, 0);
		ft_lstadd(labels, ft_lstnew(label, sizeof(t_label)));
	}
	return (label);
}

int		check_arg_type(char **args, t_op *op, t_list **labels)
{
	int i;
	int type;
	int nb_arg;

	nb_arg = count_split(args);
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
		if (is_t_dir(args[i], op->args[i]) && args[i][1] == LABEL_CHAR)
		{
			if (get_label(&args[i][2], labels))
				get_label(&args[i][2], labels)->is_used = 1;
		}
		i++;
	}
	return (1);
}

char	**get_args(char *line)
{
	char **tmp_split;
	char **args;

	tmp_split = NULL;
	args = NULL;
	if ((args = ft_strsplit(line, SEPARATOR_CHAR)) == NULL)
		ft_exit_asm("Invalid args\n");
	tmp_split = ft_strsplit_whitespace(args[0]);
	ft_strdel(&args[0]);
	args[0] = ft_strdup(tmp_split[count_split(tmp_split) - 1]);
	freesplit(&tmp_split);
	return (args);
}

t_op	*valid_op_lab(char *line, int line_n, t_list **labels)
{
	char	*opcode;
	char	**split;
	t_op	*op;

	if ((split = ft_strsplit_whitespace(line)) == NULL)
		ft_exit_asm("Error\n");
	if (split[0] && split[0][ft_strlen(split[0]) - 1] == LABEL_CHAR)
	{
		split[0][ft_strlen(split[0]) - 1] = 0;
		if (get_label(split[0], labels))
			get_label(split[0], labels)->is_declared = 1;
		opcode = ft_strdup(split[1]);
	}
	else
		opcode = ft_strdup(split[0]);
	freesplit(&split);
	if (!(op = get_op(opcode)))
	{
		ft_printfd(STDERR, "Unknown operation on \
		line %d: '%s'\n", line_n, line);
		ft_exit_asm(NULL);
	}
	ft_strdel(&opcode);
	return (op);
}

int		valid_args(char *line, int line_n, t_op *op, t_list **labels)
{
	char	**args;
	int		nb_arg;

	args = get_args(line);
	nb_arg = count_split(args);
	if (op->nb_arg != nb_arg)
	{
		if (op->nb_arg > nb_arg)
			ft_printfd(STDERR, "Not enough arguments for '%s' \
			on line %d: '%s'\n", op->op, line_n, line);
		else
			ft_printfd(STDERR, "Too many arguments for '%s' \
			on line %d: '%s'\n", op->op, line_n, line);
		ft_exit_asm(NULL);
	}
	if (check_arg_type(args, op, labels) != 1)
	{
		ft_printfd(STDERR, "Invalid arguments type \
		on line %d: '%s'\n", line_n, line);
		ft_exit_asm(NULL);
	}
	freesplit(&args);
	return (1);
}

int		check_asm(char *line, int line_n, t_list **labels)
{
	t_op	*op;

	op = valid_op_lab(line, line_n, labels);
	valid_args(line, line_n, op, labels);
	return (1);
}

void	remove_comment(char **line)
{
	char	*comm;
	char	*new_line;

	if ((comm = ft_strchr(*line, '#')))
	{
		if ((ft_strstr(*line, NAME_CMD_STRING) == *line ||
			ft_strstr(*line, COMMENT_CMD_STRING) == *line) &&
			(ft_strchr(*line, '"') < comm &&
			comm < ft_strrchr(*line, '"')))
			return ;
		else
		{
			new_line = ft_strsub(*line, 0, comm - *line);
			ft_strdel(line);
			*line = new_line;
		}
	}
}

int		check_header(char *line)
{
	static int	name = 0;
	static int	comment = 0;
	char		*first_quot;
	char		*last_quot;

	first_quot = ft_strchr(line, '"');
	last_quot = ft_strrchr(line, '"');
	if (first_quot && last_quot && ft_strstr(line, NAME_CMD_STRING) == line)
	{
		if (!(first_quot < last_quot))
			ft_exit_asm("Header name syntax error.\n");
		if (last_quot - first_quot > PROG_NAME_LENGTH)
			ft_exit_asm("Header name is to long.\n");
		name = 1;
	}
	if (first_quot && last_quot && ft_strstr(line, COMMENT_CMD_STRING) == line)
	{
		if (!(first_quot < last_quot))
			ft_exit_asm("Header comment syntax error.\n");
		if (last_quot - first_quot > COMMENT_LENGTH)
			ft_exit_asm("Header comment is to long.\n");
		comment = 1;
	}
	return (name + comment);
}

int		check_line(char **line, int line_n, int *header, t_list **labels)
{
	trim_whitespace(line);
	remove_comment(line);
	if (ft_strlen(*line) > 0)
	{
		if (*header < 2)
			*header = check_header(*line);
		else
			check_asm(*line, line_n, labels);
	}
	return (1);
}

int		check_labels(t_list *labels)
{
	while (labels)
	{
		if (!((t_label *)labels->content)->is_declared)
		{
			ft_printfd(STDERR, "Undeclared label %s.\n",
				((t_label *)labels->content)->name);
		}
		labels = labels->next;
	}
	return (1);
}

void	lexer(int fd)
{
	int		gnl;
	char	*line;
	int		line_n;
	int		header;
	t_list	*labels;

	line = NULL;
	line_n = 1;
	header = 0;
	labels = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		check_line(&line, line_n, &header, &labels);
		ft_strdel(&line);
		line_n++;
	}
	ft_strdel(&line);
	if (gnl == 0 && header != 2)
		ft_exit_asm("Missing header.\n");
	check_labels(labels);
	if (gnl == -1 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}
	lseek(fd, 0, SEEK_SET);
}
