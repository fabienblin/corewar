/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 17:09:44 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_arg(t_data *data, va_list *argv, int *ret)
{
	ft_init_data(data);
	ft_read_format(data, argv);
	ft_conversion(data, argv);
	*ret = ft_switch(data);
	if (*ret == 0)
		data->pos = data->l_pri;
	return (0);
}

int				ft_sprintf(char **str, const char *format, ...)
{
	va_list		argv;
	t_data		data;
	int			ret;

	ret = 0;
	ft_init(format, &data);
	va_start(argv, format);
	while (*data.s_for != '\0' && ret == 0)
	{
		if (*data.s_for == '%')
			ft_arg(&data, &argv, &ret);
		else if (*data.s_for == '{')
			ft_color(&data);
		else
			ft_add_caractere(&data);
	}
	va_end(argv);
	data.l_pri = (ret == -1) ? data.pos : data.l_pri;
	*str = ft_strnew(data.l_pri);
	*str = ft_memcpy(*str, data.s_pri, data.l_pri);
	free(data.s_pri);
	return (ret == -1 ? -1 : data.l_pri);
}

int				ft_fprintf(int fd, const char *format, ...)
{
	va_list		argv;
	t_data		data;
	int			ret;

	ret = 0;
	ft_init(format, &data);
	va_start(argv, format);
	while (*data.s_for != '\0' && ret == 0)
	{
		if (*data.s_for == '%')
			ft_arg(&data, &argv, &ret);
		else if (*data.s_for == '{')
			ft_color(&data);
		else
			ft_add_caractere(&data);
	}
	va_end(argv);
	data.l_pri = (ret == -1) ? data.pos : data.l_pri;
	write(fd, data.s_pri, data.l_pri);
	free(data.s_pri);
	return (ret == -1 ? -1 : data.l_pri);
}

int				ft_printf(const char *format, ...)
{
	va_list		argv;
	t_data		data;
	int			ret;

	ret = 0;
	ft_init(format, &data);
	va_start(argv, format);
	while (*data.s_for != '\0' && ret == 0)
	{
		if (*data.s_for == '%')
			ft_arg(&data, &argv, &ret);
		else if (*data.s_for == '{')
			ft_color(&data);
		else
			ft_add_caractere(&data);
	}
	va_end(argv);
	data.l_pri = (ret == -1) ? data.pos : data.l_pri;
	write(1, data.s_pri, data.l_pri);
	free(data.s_pri);
	return (ret == -1 ? -1 : data.l_pri);
}
