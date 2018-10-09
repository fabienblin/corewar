/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type_tostring.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 13:28:21 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 13:48:44 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type_exceptions(t_format *f)
{
	int	t;
	int	c;

	t = f->type;
	c = (t == 'd' || t == 'D' || t == 'o' || t == 'O' || t == 'u' || t == 'U' ||
		t == 'x' || t == 'X' || t == 'i');
	if (ft_strcmp("0", f->tostring) == 0 && f->preci == 0 && c)
		ft_strrealloc(&f->tostring, 0);
	c = (t == 'd' || t == 'D' || t == 'u' || t == 'U' || t == 'x' || t == 'X' ||
		t == 'i');
	if (ft_strcmp("0X", f->tostring) == 0 && f->preci == 0 && c)
		ft_strrealloc(&f->tostring, 0);
}

int			ft_type_tostring(t_format *f, va_list ap)
{
	if (f->type)
	{
		if (f->type == 'p')
			ft_type_p_tostring(f, ap);
		else if (f->type == 'd' || f->type == 'D' || f->type == 'i')
			ft_type_di_tostring(f, ap);
		else if (f->type == 'o' || f->type == 'O' || f->type == 'u' ||
			f->type == 'U' || f->type == 'x' || f->type == 'X')
			ft_type_uox_tostring(f, ap);
		else if (f->type == '%')
			f->tostring = ft_strdup("%");
		else if (f->type == 'c' || f->type == 'C')
		{
			if (ft_type_c_tostring(f, ap) == -1)
				return (-1);
		}
		else
		{
			if (ft_type_s_tostring(f, ap) == -1)
				return (-1);
		}
		ft_type_exceptions(f);
	}
	return (1);
}
