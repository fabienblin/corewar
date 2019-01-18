/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfree.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:48 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 16:57:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		lst->content = 0;
		lst->next = NULL;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}
