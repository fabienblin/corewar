/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_header_1.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 12:29:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:06:33 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		multiline_header_name(int fd, char **first_quot,
	char **last_quot, char **line)
{
	char	*name;

	name = NULL;
	*last_quot = NULL;
	name = ft_strdup(*first_quot);
	ft_strdel(line);
	while (get_next_line(fd, line) > 0 && !*last_quot)
	{
		*last_quot = ft_strrchr(*line, '"');
		name = ft_strjoinfree(name, *line);
	}
	ft_strdel(line);
	*first_quot = ft_strchr(name, '"');
	*last_quot = ft_strrchr(name, '"');
	if (*last_quot - *first_quot > PROG_NAME_LENGTH)
	{
		ft_strdel(&name);
		ft_exit_asm("Header name is to long.");
	}
	ft_strdel(&name);
	return (1);
}

int		multiline_header_comment(int fd, char **first_quot,
	char **last_quot, char **line)
{
	char	*name;
	int		result;

	name = NULL;
	result = 0;
	*last_quot = NULL;
	name = ft_strdup(*first_quot);
	ft_strdel(line);
	while ((result = get_next_line(fd, line)) > 0 && !*last_quot)
	{
		*last_quot = ft_strrchr(*line, '"');
		name = ft_strjoinfree(name, *line);
	}
	ft_strdel(line);
	*first_quot = ft_strchr(name, '"');
	*last_quot = ft_strrchr(name, '"');
	if (*last_quot - *first_quot > COMMENT_LENGTH || result == 0)
	{
		ft_strdel(&name);
		ft_exit_asm("Header comment is to long.");
	}
	ft_strdel(&name);
	return (1);
}

int		valid_header_name(int fd)
{
	char	*line;
	char	*first_quot;
	char	*last_quot;
	int		error;

	error = 0;
	skip_empty_lines(fd, &line);
	if (line && ft_strstr(line, NAME_CMD_STRING))
	{
		first_quot = ft_strchr(line, '"');
		last_quot = ft_strrchr(line, '"');
		if (last_quot == first_quot)
			multiline_header_name(fd, &first_quot, &last_quot, &line);
		error = last_quot < first_quot;
	}
	else
		error++;
	ft_strdel(&line);
	return (error);
}

int		valid_header_comment(int fd)
{
	char	*line;
	char	*first_quot;
	char	*last_quot;
	int		error;

	error = 0;
	skip_empty_lines(fd, &line);
	if (line && ft_strstr(line, COMMENT_CMD_STRING))
	{
		first_quot = ft_strchr(line, '"');
		last_quot = ft_strrchr(line, '"');
		if (last_quot == first_quot)
			multiline_header_comment(fd, &first_quot, &last_quot, &line);
		error = last_quot < first_quot;
	}
	else
		error++;
	ft_strdel(&line);
	return (error);
}

int		check_header(int fd)
{
	int	name;
	int	comment;

	name = 0;
	comment = 0;
	name = valid_header_name(fd);
	if (name)
		ft_exit_asm("Header name is invalid.");
	comment = valid_header_comment(fd);
	if (comment)
		ft_exit_asm("Header comment is invalid.");
	return (name + comment);
}
