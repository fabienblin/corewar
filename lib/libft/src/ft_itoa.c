/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:24 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 14:44:45 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int x)
{
	int len;

	len = 1;
	while (x /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*ret;
	int				neg;
	int				ret_size;

	neg = n < 0;
	if (neg)
		n = -n;
	ret_size = ft_intlen(n) + neg;
	if (!(ret = ft_strnew(ret_size)))
		return (NULL);
	while (ret_size > 0)
	{
		ret[--ret_size] = ((n % 10) + '0');
		n /= 10;
	}
	if (neg)
	{
		ret[0] = '-';
		ret_size--;
	}
	return (ret);
}
