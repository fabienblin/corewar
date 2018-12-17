/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 09:21:11 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compte(uintmax_t nbr, int n_base)
{
	int ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= n_base;
		ret++;
	}
	return (ret);
}

char			*ft_uitoa_base(uintmax_t nbr, char *base)
{
	char		*str;
	int			size;
	uintmax_t	tmp;
	int			n_base;

	if (nbr == 0)
	{
		str = ft_strnew(1);
		str[0] = base[0];
		return (str);
	}
	n_base = ft_strlen(base);
	size = ft_compte(nbr, n_base);
	str = ft_strnew(size);
	tmp = nbr;
	size--;
	while (tmp != 0)
	{
		str[size] = base[tmp % n_base];
		tmp /= n_base;
		size--;
	}
	return (str);
}
