/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:15:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:21:37 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int		check_label_declarations(t_list *labels)
{
	int	errors;

	errors = 0;
	while (labels)
	{
		if (!((t_label *)labels->content)->is_declared)
		{
			ft_printfd(STDERR, "Undeclared label %s.\n",
				((t_label *)labels->content)->name);
			errors++;
		}
		labels = labels->next;
	}
	if (errors)
		ft_exit_asm(NULL);
	return (1);
}

void	lexer(int fd)
{
	int		gnl;
	char	*line;
	t_list	*labels;

	labels = NULL;
	if (check_header(fd))
		ft_exit_asm("Header error.\n");
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		trim_whitespace(&line);
		remove_comment(&line);
		check_line(line, &labels);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	check_label_declarations(labels);
	ft_lstdel(&labels, del_label);
	if (gnl == -1 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}
	lseek(fd, 0, SEEK_SET);
}
