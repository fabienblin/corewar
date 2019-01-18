/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memjoin.c                                     .::    .:/ .      .::   */
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

void	*ft_memjoin(const void *s1, size_t l_s1, const void *s2, size_t l_s2)
{
	char	*ad;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if ((ad = ft_strnew(l_s1 + l_s2)) == NULL)
		return (NULL);
	ad = ft_memcpy(ad, s1, l_s1);
	ad = ft_memcat(ad, l_s1, s2, l_s2);
	return (ad);
}
