/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:24 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:24 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new;
	t_list	*lstdup;

	new = NULL;
	lstdup = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		ft_lstadd(&lstdup, new);
		lst = lst->next;
	}
	return (lstdup);
}
