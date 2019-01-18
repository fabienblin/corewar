/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:47 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	int		len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_neg(int n)
{
	int		i;
	char	*tmp;

	i = ft_len(n);
	if ((tmp = ft_strnew(i)) == NULL)
		return (NULL);
	tmp[0] = '-';
	n = -n;
	i -= 1;
	while (n > 0)
	{
		tmp[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (tmp);
}

static char	*ft_pos(int n)
{
	int		i;
	char	*tmp;

	i = ft_len(n);
	if ((tmp = ft_strnew(i + 1)) == NULL)
		return (NULL);
	i -= 1;
	while (n > 0)
	{
		tmp[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (tmp);
}

char		*ft_itoa(int n)
{
	char	*tmp;

	tmp = NULL;
	if (n == -2147483648)
	{
		if ((tmp = ft_strnew(ft_len(-2147483648) + 1)) == NULL)
			return (NULL);
		ft_strcpy(tmp, "-2147483648");
	}
	else if (n == -0)
	{
		if ((tmp = ft_strnew(ft_len(0) + 1)) == NULL)
			return (NULL);
		ft_strcpy(tmp, "0");
	}
	else if (n < 0)
		tmp = ft_neg(n);
	else if (n >= 0)
		tmp = ft_pos(n);
	return (tmp);
}
