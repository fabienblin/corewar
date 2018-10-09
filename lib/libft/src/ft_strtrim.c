/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:30 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:30 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*s_origin;
	char	*s_end;

	str = NULL;
	if (s)
	{
		s_origin = (char *)s;
		s_end = (char *)s + ft_strlen(s) - 1;
		while (ft_iswhite(*s_origin) || ft_iswhite(*s_end))
		{
			if (ft_iswhite(*s_origin))
				s_origin++;
			if (ft_iswhite(*s_end))
				s_end--;
		}
		if (s_origin <= s_end)
		{
			if (!(str = ft_strsub(s, (s_origin - s), (s_end - s_origin + 1))))
				return (NULL);
		}
		else
			str = s_origin;
	}
	return (str);
}
