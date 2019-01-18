/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wchar.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 11:31:45 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_wchar(wchar_t c)
{
	char	*str;

	str = ft_strnew(5);
	ft_strclr(str);
	if (c < 0x80)
		str[0] = c;
	else if (c < 0x800)
	{
		str[0] = (0xC0 | (c >> 6));
		str[1] = (0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		str[0] = (0xE0 | (c >> 12));
		str[1] = (0x80 | (c >> 6 & 0x3F));
		str[2] = (0x80 | (c & 0x3F));
	}
	else if (c < 0x200000)
	{
		str[0] = (0xF0 | (c >> 18));
		str[1] = (0x80 | (c >> 12 & 0x3F));
		str[2] = (0x80 | (c >> 6 & 0x3F));
		str[3] = (0x80 | (c & 0x3F));
	}
	return (str);
}

char			*ft_w_char(t_data *data)
{
	wchar_t		c;
	char		*str;

	str = NULL;
	if (MB_CUR_MAX == 1 && data->argument > 127 && data->argument < 256)
		data->argument = (char)data->argument;
	c = data->argument;
	str = ft_wchar(c);
	return (str);
}

static int		ft_verif(t_data *data, wchar_t *tmp)
{
	if (data->point && data->i < data->precision)
	{
		if (MB_CUR_MAX == 1 && *tmp > 255)
			data->ret = -1;
		if (MB_CUR_MAX != 1 && (*tmp > 0x10ffff || *tmp < 0
			|| (*tmp > 0xd7ff && *tmp < 0xe000)))
			data->ret = -1;
	}
	else if (!data->point)
	{
		if (MB_CUR_MAX == 1 && *tmp > 255)
			data->ret = -1;
		if (MB_CUR_MAX != 1 && (*tmp > 0x10ffff || *tmp < 0
			|| (*tmp > 0xd7ff && *tmp < 0xe000)))
			data->ret = -1;
	}
	return (0);
}

char			*ft_w_string(t_data *data)
{
	wchar_t		*tmp;
	wint_t		car;
	char		*str;
	char		*rep_cpy;
	char		*rep;

	data->ret = 0;
	data->i = 0;
	tmp = (wchar_t*)data->argument;
	rep = ft_strnew(0);
	while (*tmp != '\0')
	{
		ft_verif(data, tmp);
		car = (MB_CUR_MAX == 1 && *tmp > 127 && *tmp < 256) ?
			(char)*tmp : (wchar_t)*tmp;
		str = ft_wchar(car);
		rep_cpy = rep;
		rep = ft_strjoin(rep_cpy, str);
		free(str);
		free(rep_cpy);
		tmp++;
		data->i++;
	}
	return (rep);
}
