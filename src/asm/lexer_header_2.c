/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_header_2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 19:11:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 19:14:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	skip_empty_lines(int fd, char **line)
{
	while (get_next_line(fd, line) > 0)
	{
		trim_whitespace(line);
		remove_comment(line);
		if (ft_strlen(*line))
			break ;
		ft_strdel(line);
	}
}
