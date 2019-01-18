/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:49 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((new->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
