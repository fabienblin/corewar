/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 18:25:57 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:32:26 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_reader	*ft_rdrnew(int fd)
{
	t_reader	*new;

	if (!(new = (t_reader *)malloc(sizeof(t_reader))))
		return (NULL);
	new->fd = fd;
	new->prev = NULL;
	return (new);
}

static t_reader	*ft_getreader(t_list **rdr_lst, int fd)
{
	t_reader	*rdr;
	t_list		*lst;

	lst = *rdr_lst;
	while (lst)
	{
		rdr = (t_reader *)lst->content;
		if (rdr->fd == fd)
			return (rdr);
		lst = lst->next;
	}
	if (!lst)
	{
		if (!(lst = ft_lstnew(NULL, 0)))
			return (NULL);
		if (!(rdr = ft_rdrnew(fd)))
			return (NULL);
		lst->content = rdr;
		ft_lstadd(rdr_lst, lst);
	}
	return (rdr);
}

static int		get_line(t_reader *rdr, char **line)
{
	int		siz;
	char	*eol;
	char	buf[BUFF_SIZE + 1];

	while (!(eol = ft_strchr(rdr->prev, '\n'))
	&& (siz = read(rdr->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[siz] = 0;
		rdr->prev = ft_strfreejoin(rdr->prev, buf);
	}
	if (eol)
	{
		siz = ft_strlen(eol + 1) + 1;
		*line = ft_strsub(rdr->prev, 0, eol - rdr->prev);
		ft_strncpy(rdr->prev, eol + 1, siz);
		ft_realloc((void **)&rdr->prev, siz);
	}
	else
	{
		siz = ft_strlen(rdr->prev);
		*line = ft_strdup(rdr->prev);
		free(rdr->prev);
		rdr->prev = NULL;
	}
	return (siz);
}

void			delrdrlst(void *rdr, size_t size)
{
	(void)size;
	if (rdr)
	{
		if (((t_reader *)rdr)->prev)
			free(((t_reader *)rdr)->prev);
	}
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*rdr_lst = NULL;
	int				gnl;
	t_reader		*rdr;
	char			buf[1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	rdr = ft_getreader(&rdr_lst, fd);
	gnl = get_line(rdr, line);
	if (gnl <= 0)
	{
		ft_strdel(line);
		ft_lstdel(&rdr_lst, delrdrlst);
	}
	return (gnl > 0 ? 1 : gnl);
}
