/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:29 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:29 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t src_len;

	src_len = ft_strlen(src);
	dst = (char *)ft_memcpy(dst, src, n);
	if (src_len < n)
		ft_bzero(&dst[src_len], n - src_len);
	return (dst);
}
