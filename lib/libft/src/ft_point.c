/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 15:31:47 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/02 17:15:50 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_point	*ft_newpoint(int x, int y)
{
	t_point *p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	return (p);
}

void	ft_delpoint(t_point **p)
{
	free(*p);
	*p = NULL;
}
