/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:25 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:25 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	car;
	unsigned char	*str;

	i = 0;
	car = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == car)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
