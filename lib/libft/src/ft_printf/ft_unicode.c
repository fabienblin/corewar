/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unicode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 13:28:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 13:49:21 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wstr_unilen_preci(wchar_t *src, int preci)
{
	int		len;
	int		i;

	if (!src)
		return (0);
	len = 0;
	i = -1;
	while (src[++i] && i < preci)
	{
		if ((src[i] >= 0xD800 && src[i] <= 0xDFFF) || src[i] < 0 ||
			(MB_CUR_MAX == 1 && src[i] > 0xFF) || src[i] > 0x10FFFF)
			return (-1);
		if ((MB_CUR_MAX > 1 && src[i] <= 0x7F) ||
			(MB_CUR_MAX == 1 && src[i] <= 0xFF))
			len += 1;
		else if (src[i] <= 0x7FF && MB_CUR_MAX >= 2)
			len += 2;
		else if (src[i] <= 0xFFFF && MB_CUR_MAX >= 3)
			len += 3;
		else if (src[i] <= 0x10FFFF && MB_CUR_MAX >= 4)
			len += 4;
		else
			break ;
	}
	return (len);
}

static int	ft_wstr_unilen(wchar_t *src)
{
	int		len;
	int		i;

	if (!src)
		return (0);
	len = 0;
	i = -1;
	while (src[++i])
	{
		if ((src[i] >= 0xD800 && src[i] <= 0xDFFF) || src[i] < 0 ||
			(MB_CUR_MAX == 1 && src[i] > 0xFF) || src[i] > 0x10FFFF)
			return (-1);
		if ((MB_CUR_MAX > 1 && src[i] <= 0x7F) ||
			(MB_CUR_MAX == 1 && src[i] <= 0xFF))
			len += 1;
		else if (src[i] <= 0x7FF && MB_CUR_MAX >= 2)
			len += 2;
		else if (src[i] <= 0xFFFF && MB_CUR_MAX >= 3)
			len += 3;
		else if (src[i] <= 0x10FFFF && MB_CUR_MAX >= 4)
			len += 4;
		else
			break ;
	}
	return (len);
}

static void	ft_conv(char *dst, wchar_t *src, int *i, int *j)
{
	if ((MB_CUR_MAX > 1 && src[*i] <= 0x7F) ||
		(MB_CUR_MAX == 1 && src[*i] <= 0xFF))
		dst[(*j)++] = src[*i];
	else if (src[*i] <= 0x7FF && MB_CUR_MAX >= 2)
	{
		dst[(*j)++] = (src[*i] >> 6) + 0xC0;
		dst[(*j)++] = (src[*i] & 0x3F) + 0x80;
	}
	else if (src[*i] <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		dst[(*j)++] = (src[*i] >> 12) + 0xE0;
		dst[(*j)++] = ((src[*i] >> 6) & 0x3F) + 0x80;
		dst[(*j)++] = (src[*i] & 0x3F) + 0x80;
	}
	else if (src[*i] <= 0x10FFFF && MB_CUR_MAX >= 4)
	{
		dst[(*j)++] = (src[*i] >> 18) + 0xF0;
		dst[(*j)++] = ((src[*i] >> 12) & 0x3F) + 0x80;
		dst[(*j)++] = ((src[*i] >> 6) & 0x3F) + 0x80;
		dst[(*j)++] = (src[*i] & 0x3F) + 0x80;
	}
}

static int	ft_wstr_unicpy(char **dst, wchar_t *src, int len)
{
	int		i;
	int		j;

	if (!src)
		return (0);
	i = -1;
	j = 0;
	while (src[++i] && j < len)
	{
		ft_conv(*dst, src, &i, &j);
	}
	return (j <= i ? j : i);
}

int			ft_convert_wstr_to_str(char **dst, wchar_t *wstr, int limit)
{
	int		new_len;

	if (!wstr)
		return (0);
	if (limit > 0 && (new_len = ft_wstr_unilen_preci(wstr, limit)) == -1)
		return (-1);
	else if (limit <= 0 && (new_len = ft_wstr_unilen(wstr)) == -1)
		return (-1);
	if ((*dst = ft_strnew(new_len)))
		ft_wstr_unicpy(dst, wstr, new_len);
	return (new_len);
}
