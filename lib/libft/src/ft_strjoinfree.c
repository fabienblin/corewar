/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:18:51 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:33:34 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*join;

	if (!(join = ft_strjoin(s1, s2)))
		return (NULL);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (join);
}
