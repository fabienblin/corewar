/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:22 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 15:53:53 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

static int	ft_iswhite(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v');
}

int			ft_atoi(const char *str)
{
	unsigned int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	if (str)
	{
		while (*str && ft_iswhite(*str))
			str++;
		if (ft_issign(*str))
			sign = (*str++ == '-' ? -1 : 1);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return ((int)ret * sign);
			ret = (ret * 10) + (*str - '0');
			str++;
		}
	}
	return ((int)ret * sign);
}
