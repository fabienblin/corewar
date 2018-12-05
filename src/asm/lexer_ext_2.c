/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_ext_2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 15:28:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 15:34:40 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

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

int		check_asm(char *line, int line_n, t_list **labels)
{
	t_op	*op;

	op = valid_op_lab(line, line_n, labels);
	valid_args(line, line_n, op, labels);
	return (1);
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
