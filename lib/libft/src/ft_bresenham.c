/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bresenham.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 14:19:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/02 17:17:26 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	tracex(t_grid *grid, t_seg *seg, int val)
{
	int x;
	int y;
	int cumul;
	int i;

	x = seg->a->x;
	y = seg->a->y;
	cumul = seg->dx / 2;
	i = 1;
	while (i <= seg->dx)
	{
		x += seg->xinc;
		cumul += seg->dy;
		if (cumul >= seg->dx)
		{
			cumul -= seg->dx;
			y += seg->yinc;
		}
		grid->data[y][x] = val;
		i++;
	}
}

static void	tracey(t_grid *grid, t_seg *seg, int val)
{
	int x;
	int y;
	int cumul;
	int i;

	x = seg->a->x;
	y = seg->a->y;
	cumul = seg->dy / 2;
	i = 1;
	while (i <= seg->dy)
	{
		y += seg->yinc;
		cumul += seg->dx;
		if (cumul >= seg->dy)
		{
			cumul -= seg->dy;
			x += seg->xinc;
		}
		grid->data[y][x] = val;
		i++;
	}
}

void		bresenham(t_grid *grid, t_seg *seg, int val)
{
	if (seg && grid)
	{
		grid->data[seg->a->y][seg->a->x] = val;
		if (seg->dx > seg->dy)
			tracex(grid, seg, val);
		else
			tracey(grid, seg, val);
	}
}
