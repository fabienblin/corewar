/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_asm_1.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 15:28:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 18:03:24 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

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
