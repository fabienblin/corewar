/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:29 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:29 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	char			*ret_origin;
	unsigned int	i;

	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	ret_origin = ret;
	i = 0;
	while (*s)
		*ret++ = f(i++, *s++);
	return (ret_origin);
}
