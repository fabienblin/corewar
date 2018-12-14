/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_asm_2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 15:25:17 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 16:15:47 by fablin      ###    #+. /#+    ###.fr     */
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
		{
			label = (t_label *)lst->content;
			return (label);
		}
		lst = lst->next;
	}
	if (!label)
	{
		label = new_label(label_name, 0, 0);
		ft_lstadd(labels, ft_lstnew(label, sizeof(t_label)));
		free(label);
		return ((t_label *)(*labels)->content);
	}
	return (NULL);
}

int		check_arg_type(char **args, t_op *op, t_list **labels)
{
	int		i;
	int		type;
	int		nb_arg;
	t_label	*lab;

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
			if ((lab = get_label(&args[i][2], labels)))
				lab->is_used = 1;
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

char	*get_op_on_line(char *line, t_list **labels, char **split)
{
	char	*opcode;
	t_label	*lab;

	if (split[0] && split[0][ft_strlen(split[0]) - 1] == LABEL_CHAR)
	{
		split[0][ft_strlen(split[0]) - 1] = 0;
		if ((lab = get_label(split[0], labels)))
		{
			if (lab->is_declared == 0)
				lab->is_declared = 1;
			else
			{
				ft_printfd(STDERR, "Label is allready declared on line : \
				'%s'\n", line);
				ft_exit_asm(NULL);
			}
		}
		opcode = ft_strdup(split[1]);
	}
	else
		opcode = ft_strdup(split[0]);
	return (opcode);
}

int		valid_args(char *line, t_op *op, t_list **labels)
{
	char	**args;
	int		nb_arg;

	args = get_args(line);
	nb_arg = count_split(args);
	if (op->nb_arg != nb_arg)
	{
		if (op->nb_arg > nb_arg)
			ft_printfd(STDERR, "Not enough arguments for '%s' \
			on line : '%s'\n", op->op, line);
		else
			ft_printfd(STDERR, "Too many arguments for '%s' \
			on line : '%s'\n", op->op, line);
		ft_exit_asm(NULL);
	}
	if (check_arg_type(args, op, labels) != 1)
	{
		ft_printfd(STDERR, "Invalid arguments type on line : '%s'\n", line);
		ft_exit_asm(NULL);
	}
	freesplit(&args);
	return (1);
}
