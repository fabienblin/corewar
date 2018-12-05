/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 15:30:01 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

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
