/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_asm_1.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 15:28:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 14:51:52 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_op	*valid_op_lab(char *line, t_list **labels)
{
	char	*opcode;
	char	**split;
	t_op	*op;

	split = ft_strsplit_whitespace(line);
	opcode = get_op_on_line(line, labels, split);
	freesplit(&split);
	if (!(op = get_op(opcode)) && opcode)
	{
		ft_printfd(STDERR, "Unknown operation on line : '%s'\n", line);
		ft_exit_asm(NULL);
	}
	ft_strdel(&opcode);
	return (op);
}

void	remove_comment(char **line)
{
	char	*comm;
	char	*new_line;

	if ((comm = ft_strchr(*line, COMMENT_CHAR)))
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

int		check_line(char *line, t_list **labels)
{
	t_op	*op;

	if (ft_strlen(line) > 0)
	{
		op = valid_op_lab(line, labels);
		if (op)
			valid_args(line, op, labels);
	}
	return (1);
}
