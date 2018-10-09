/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:29 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:29 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ret;
	char *ret_origin;

	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	ret_origin = ret;
	while (*s)
	{
		*ret = f(*s);
		ret++;
		s++;
	}
	return (ret_origin);
}
