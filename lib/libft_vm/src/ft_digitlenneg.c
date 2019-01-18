/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_digitlen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 15:44:57 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:25:23 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitlenneg(long long n)
{
	int	res;

	res = 0;
	if (n == LONG_MIN)
	{
		n += 1;
		n = -n;
		res++;
	}
	else if (n < 0)
	{
		n = -n;
		res++;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}
