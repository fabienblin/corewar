/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_type.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 13:45:08 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 19:11:35 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_base(intmax_t x, int base)
{
	int len;

	len = 1;
	while (x /= base)
		len++;
	return (len);
}

static int	ft_uintlen_base(uintmax_t x, int base)
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

char		*ft_intmax_itoa_type(intmax_t n, char t)
{
	char	*ret;
	int		ret_size;
	int		base;
	int		neg;

	if (n < -9223372036854775807)
	{
		ret = ft_strjoinfree(ft_strdup("-"), ft_uintmax_itoa_type(n, t));
		return (ret);
	}
	base = ft_get_type_base(t);
	neg = (n < 0);
	n = neg ? -n : n;
	ret_size = ft_intlen_base(n, base) + neg;
	if (!(ret = ft_strnew(ret_size)))
		return (NULL);
	while (ret_size > 0)
	{
		ret[--ret_size] = ft_base_tochar(n % base, base);
		n /= base;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}

char		*ft_uintmax_itoa_type(uintmax_t n, char t)
{
	char	*ret;
	int		ret_size;
	int		base;

	base = ft_get_type_base(t);
	ret_size = ft_uintlen_base(n, base);
	if (!(ret = ft_strnew(ret_size)))
		return (NULL);
	while (ret_size > 0)
	{
		ret[--ret_size] = ft_base_tochar(n % base, base);
		n /= base;
	}
	return (ret);
}
