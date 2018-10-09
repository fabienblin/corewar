/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_preci_tostring.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 15:14:08 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 13:50:01 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unilen(unsigned char *str, int preci)
{
	int		octet;
	int		len;

	if (!str)
		return (0);
	octet = 0;
	len = ft_strlen((char *)str);
	while (str[octet] && octet <= preci && octet < len)
	{
		if (octet + 2 <= preci && str[octet] >= 0xC0 && str[octet] <= 0xDF)
			octet += 2;
		else if (octet + 3 <= preci && str[octet] >= 0xE0 && str[octet] <= 0xEF)
			octet += 3;
		else if (octet + 4 <= preci && str[octet] >= 0xF0 && str[octet] <= 0xF7)
			octet += 4;
		else if (octet + 1 <= preci &&
			((str[octet] >= 0x01 && str[octet] <= 0xFF && MB_CUR_MAX == 1) ||
			(str[octet] >= 0x01 && str[octet] <= 0x7F && MB_CUR_MAX > 1)))
			octet += 1;
		else
			break ;
	}
	return (octet);
}

static char	*ft_unirealloc(char **src, int preci)
{
	char	*new;
	int		len;

	new = src[0];
	len = ft_unilen((unsigned char *)src[0], preci);
	if ((new = ft_strnew(len)))
	{
		ft_strncpy(new, *src, len);
		free(*src);
		*src = new;
	}
	return (new);
}

void		ft_preci_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;

	if (!(f->type == 'c' || f->type == 'C'))
	{
		if ((f->type == 's' || f->type == 'S') &&
			f->preci < (int)ft_strlen(f->tostring))
			f->tostring = ft_unirealloc(&f->tostring, f->preci);
		else if (!(f->type == 's' || f->type == 'S' || f->type == '%') &&
			f->preci >= (int)ft_strlen(f->tostring))
		{
			tmp_len = f->preci - ft_strlen(f->tostring);
			if (f->type == 'p')
				tmp_len += 2;
			tmp = ft_strgen('0', tmp_len);
			if (ft_strchr(f->tostring, '-'))
			{
				tmp = ft_strjoinfree(ft_strdup("-"), tmp);
				*ft_strchr(f->tostring, '-') = '0';
			}
			f->tostring = ft_strjoinfree(tmp, f->tostring);
		}
	}
}
