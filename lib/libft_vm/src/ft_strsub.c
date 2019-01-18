/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:57 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ad;
	char			*ss;

	i = 0;
	ss = (char *)s;
	if (ss == NULL)
		return (NULL);
	if (start > ft_strlen(ss))
		return (NULL);
	if ((ad = (char *)malloc(sizeof(*ad) * len + 1)) == NULL)
		return (NULL);
	while (i < len && ss[start + i] != '\0')
	{
		ad[i] = ss[start + i];
		i++;
	}
	ad[i] = '\0';
	return (ad);
}
