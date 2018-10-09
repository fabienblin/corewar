/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfreejoin.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/01 19:40:09 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/01 19:40:46 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strfreejoin(char *s1, char *s2)
{
	char *join;

	join = NULL;
	if (!s1)
		join = ft_strdup(s2);
	else if (!s2)
	{
		join = ft_strdup(s1);
		free(s1);
	}
	else
	{
		join = ft_strjoin(s1, s2);
		free(s1);
	}
	return (join);
}
