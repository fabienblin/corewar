/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 11:15:36 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_tostring(t_format *f, va_list ap)
{
	t_format	*first;

	first = f;
	while (f)
	{
		if (ft_type_tostring(f, ap) == -1)
		{
			f->err = 1;
			return ;
		}
		if (f->preci >= 0)
			ft_preci_tostring(f);
		ft_flags_tostring(f);
		if (f->width > 0)
			ft_width_tostring(f);
		f = f->next;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*f;
	int			octet;

	f = ft_parse((char *)format);
	va_start(ap, format);
	ft_tostring(f, ap);
	va_end(ap);
	octet = ft_puttostring_fd(f, 1);
	ft_del_format_lst(f);
	return (octet);
}

int			ft_printfd(int fd, const char *format, ...)
{
	va_list		ap;
	t_format	*f;
	int			octet;

	f = ft_parse((char *)format);
	va_start(ap, format);
	ft_tostring(f, ap);
	va_end(ap);
	octet = ft_puttostring_fd(f, fd);
	ft_del_format_lst(f);
	return (octet);
}
