/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:49 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstncat(t_list *lst_dst, t_list *lst_src, size_t n)
{
	t_list	*dst;
	t_list	*src;
	size_t	i;

	i = 0;
	dst = lst_dst;
	src = lst_src;
	if (dst == NULL || src == NULL || n <= 0)
		return (NULL);
	while (dst->next != NULL)
		dst = dst->next;
	dst->next = src;
	while (dst->next != NULL && i++ < n)
		dst = dst->next;
	if (dst->next != NULL)
	{
		ft_lstfree(dst->next);
		dst->next = NULL;
	}
	return (lst_dst);
}
