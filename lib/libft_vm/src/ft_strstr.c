/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:56 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *src, const char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (str[i] == '\0')
		return ((char *)src);
	while (src[i] != '\0')
	{
		j = 0;
		while (str[j] == src[i + j])
		{
			if (str[j + 1] == '\0')
				return ((char *)src + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
