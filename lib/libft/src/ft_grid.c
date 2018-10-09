/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_grid.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 15:33:25 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/02 16:46:02 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_grid	*ft_newgrid(int x, int y)
{
	t_grid	*new;
	int		i;

	if (!(new = (t_grid *)malloc(sizeof(t_grid))))
		return (NULL);
	new->x = x;
	new->y = y;
	if (x > 0 && y > 0)
	{
		if (!(new->data = (int **)malloc(sizeof(int) * y + 1)))
			return (NULL);
		new->data[y] = NULL;
		i = 0;
		while (i < y)
		{
			if (!(new->data[i] = (int *)ft_strnew(x)))
				return (NULL);
			i++;
		}
	}
	return (new);
}

void	ft_delgrid(t_grid **grid)
{
	int i;

	i = 0;
	while (i < (*grid)->y)
	{
		free((*grid)->data[i]);
		i++;
	}
	free(*grid);
	*grid = NULL;
}
