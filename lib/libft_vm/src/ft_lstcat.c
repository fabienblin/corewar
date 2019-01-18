/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:48 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcat(t_list *lst_dst, t_list *lst_src)
{
	t_list	*dst;
	t_list	*src;

	dst = lst_dst;
	src = lst_src;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (dst->next != NULL)
		dst = dst->next;
	dst->next = src;
	return (lst_dst);
}
