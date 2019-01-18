/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:55 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	j;
	char			*ad;

	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	if ((ad = (char *)malloc(sizeof(*ad) * i + 1)) == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		ad[j] = f(s[j]);
		j++;
	}
	ad[j] = '\0';
	return (ad);
}
