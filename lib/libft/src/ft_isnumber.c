/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isnumber.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 13:14:50 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:14:55 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] != '+' && str[i] != '-')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
