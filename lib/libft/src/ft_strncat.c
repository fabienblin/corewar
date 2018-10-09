/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:29 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:29 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int s1_len;
	int i;

	s1_len = ft_strlen(s1);
	i = 0;
	while ((int)n > i && *s2)
	{
		*(s1 + s1_len + i) = *(char *)s2;
		i++;
		s2++;
	}
	*(s1 + s1_len + i) = 0;
	return (s1);
}
