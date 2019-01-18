/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:52 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcat(void *dst, size_t start, const void *src, size_t len_src)
{
	size_t					i;
	unsigned char			*dst_tmp;
	const unsigned char		*src_tmp;

	dst_tmp = dst;
	src_tmp = (const unsigned char *)src;
	i = 0;
	while (i != len_src)
	{
		dst_tmp[start + i] = src_tmp[i];
		i++;
	}
	return (dst);
}
