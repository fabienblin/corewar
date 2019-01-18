/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   my_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 15:34:31 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 15:34:31 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void				*my_memalloc(t_free **lst_free, size_t size)
{
	void		*rep;
	t_free		*link;

	if (!(rep = ft_memalloc(size)))
		exit(my_exit(lst_free, __FILE__, (char *)__func__, __LINE__));
	if (!(link = ft_memalloc(sizeof(t_free))))
	{
		free(rep);
		exit(my_exit(lst_free, __FILE__, (char *)__func__, __LINE__));
	}
	if (!*lst_free)
	{
		link->address = (size_t)rep;
		*lst_free = link;
	}
	else
	{
		link->address = (size_t)rep;
		link->next = *lst_free;
		*lst_free = link;
	}
	return (rep);
}

static void			my_free_3(t_free **lst_free, t_free *f, t_free *p)
{
	t_free		*tmp;

	tmp = (*lst_free)->next;
	p->next = tmp;
	free((void *)(*lst_free)->address);
	free(*lst_free);
	*lst_free = f;
}

static void			my_free_2(t_free **lst_free, size_t address)
{
	t_free		*first;
	t_free		*prev;

	first = *lst_free;
	prev = NULL;
	while (*lst_free && (*lst_free)->address != address)
	{
		prev = *lst_free;
		*lst_free = (*lst_free)->next;
	}
	if (prev && !(*lst_free)->next)
	{
		free((void *)(*lst_free)->address);
		free(*lst_free);
		prev->next = NULL;
		*lst_free = first;
	}
	else if (prev && (*lst_free)->next)
		my_free_3(lst_free, first, prev);
	else
		exit(my_exit(lst_free, __FILE__, (char *)__func__, __LINE__));
}

void				my_free(t_free **lst_free, size_t address)
{
	t_free		*tmp;

	if ((*lst_free)->address == address)
	{
		tmp = (*lst_free)->next;
		free((void *)(*lst_free)->address);
		free(*lst_free);
		*lst_free = tmp;
	}
	else
		my_free_2(lst_free, address);
}

void				my_auto_free(t_free **lst_free)
{
	t_free	*tmp;

	while ((*lst_free))
	{
		if ((*lst_free)->next)
			tmp = (*lst_free)->next;
		else
			tmp = NULL;
		free((void *)(*lst_free)->address);
		free(*lst_free);
		(*lst_free) = tmp;
	}
}
