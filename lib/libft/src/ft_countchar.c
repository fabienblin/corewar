/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countchar.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 13:16:02 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:17:03 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countchar(char *str, char c)
{
	int i;
	int compt;

	i = 0;
	compt = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			compt++;
		i++;
	}
	return (compt);
}
