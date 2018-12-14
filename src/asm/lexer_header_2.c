/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_header_2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 19:11:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 16:02:49 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	skip_empty_lines(int fd, char **line)
{
	int	len;
	int	gnl;

	len = 0;
	while ((gnl = get_next_line(fd, line)) > 0)
	{
		trim_whitespace(line);
		remove_comment(line);
		len = ft_strlen(*line);
		if (len)
			break ;
		ft_strdel(line);
	}
	if (gnl == -1 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}
}
