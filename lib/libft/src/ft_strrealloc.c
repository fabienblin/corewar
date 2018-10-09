/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrealloc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/09 14:41:51 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 20:45:11 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char **str, size_t size)
{
	char	*s;

	s = NULL;
	if (!(s = ft_strnew(size)))
		return (NULL);
	if (str && *str)
	{
		ft_strncpy(s, *str, size);
		free(*str);
		*str = s;
	}
	return (s);
}
