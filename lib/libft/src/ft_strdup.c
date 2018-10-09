/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:28 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 15:21:03 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	s_len;

	if (!s1)
		return (NULL);
	s_len = (size_t)ft_strlen(s1);
	if (!(dup = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	dup[s_len] = 0;
	dup = ft_strcpy(dup, s1);
	return (dup);
}
