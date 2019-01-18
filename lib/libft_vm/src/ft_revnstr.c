/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_revnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 11:45:24 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 11:45:24 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revnstr(char *str, int oct)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_memalloc(oct + 1)))
		return (NULL);
	while (oct >= 0)
	{
		oct--;
		tmp[i] = str[oct];
		i++;
	}
	return (tmp);
}
