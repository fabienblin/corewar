/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 16:52:26 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 13:47:26 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int x, int base)
{
	int len;

	len = 1;
	while (x /= base)
		len++;
	return (len);
}

static char	ft_base_tochar(int toprint, int base)
{
	if (base > 10 && toprint >= 10)
		return ('A' + toprint - 10);
	return ('0' + toprint);
}

char		*ft_itoa_base(int n, int base)
{
	char			*ret;
	int				neg;
	int				ret_size;

	neg = n < 0;
	if (neg)
		n = -n;
	ret_size = ft_intlen(n, base) + neg;
	if (!(ret = ft_strnew(ret_size)))
		return (NULL);
	while (ret_size > 0)
	{
		ret[--ret_size] = ft_base_tochar(n % base, base);
		n /= base;
	}
	if (neg)
	{
		ret[0] = '-';
		ret_size--;
	}
	return (ret);
}
