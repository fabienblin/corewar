/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:25 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/06 21:29:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				ret;
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 && s2)
	{
		ret = 0;
		i = 0;
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		while ((int)n > i)
		{
			if (str1[i] != str2[i])
				return (str1[i] - str2[i]);
			i++;
		}
		return (ret);
	}
	return (1);
}
