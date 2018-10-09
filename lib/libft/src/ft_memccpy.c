/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:25 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:25 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	car;
	unsigned char	*d;
	unsigned char	*s;

	car = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (n)
	{
		while (n--)
		{
			*d = *s;
			if (*s == car)
				return ((void *)d + 1);
			d++;
			s++;
		}
	}
	return (NULL);
}
