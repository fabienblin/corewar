/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsupchr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 18:39:27 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 18:44:45 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsupchr(const char *s, int c)
{
	int i;
	int n;

	i = 0;
	n = (int)ft_strlen(s);
	while (i <= n)
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
