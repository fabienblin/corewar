/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:48 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list			*ft_lstdup(const t_list *lst)
{
	t_list	*new;
	t_list	*begin;

	if (lst == NULL)
		return (NULL);
	if ((new = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		if ((new->next = ft_lstnew(lst->content, lst->content_size)) == NULL)
		{
			ft_lstfree(begin);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
