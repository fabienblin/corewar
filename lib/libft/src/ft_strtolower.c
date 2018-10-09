/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtolower.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 18:15:52 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 20:43:50 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char *s;

	s = str;
	if (!s)
		return (NULL);
	while (*s)
	{
		*s = (wchar_t)ft_tolower(*s);
		s++;
	}
	return (str);
}
