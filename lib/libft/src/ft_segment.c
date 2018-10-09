/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_segment.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 15:32:33 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/02 15:41:28 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_seg	*ft_newsegment(t_point *a, t_point *b)
{
	t_seg	*seg;

	if (!(seg = (t_seg *)malloc(sizeof(t_seg))))
		return (NULL);
	ft_bzero(seg, sizeof(t_seg));
	if (!a)
		a = ft_newpoint(0, 0);
	if (!b)
		b = ft_newpoint(0, 0);
	if (a && b)
	{
		seg->a = a;
		seg->b = b;
		seg->dx = b->x - a->x;
		seg->dy = b->y - a->y;
		seg->xinc = (seg->dx > 0 ? 1 : -1);
		seg->yinc = (seg->dy > 0 ? 1 : -1);
		seg->dx = abs(seg->dx);
		seg->dy = abs(seg->dy);
	}
	return (seg);
}

void	ft_delsegment(t_seg **seg)
{
	ft_delpoint(&(*seg)->a);
	ft_delpoint(&(*seg)->b);
	free(*seg);
	*seg = NULL;
}
