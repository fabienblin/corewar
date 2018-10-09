/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_width_tostring.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 15:14:12 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 13:49:46 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_tostring_more(t_format *f)
{
	char *p;

	if (f->type == 'd' || f->type == 'D' || f->type == 'i')
	{
		if ((p = ft_strchr(f->tostring, '+')) && (p[-1] == '0'))
		{
			f->tostring[0] = '+';
			*p = '0';
		}
		if ((p = ft_strchr(f->tostring, '-')) && (p[-1] == '0'))
		{
			f->tostring[0] = '-';
			*p = '0';
		}
	}
}

void		ft_width_tostring(t_format *f)
{
	char	*width;
	int		width_len;

	width = NULL;
	width_len = f->width - ft_strlen(f->tostring);
	if ((f->type == 'c' || f->type == 'C') && f->arg == NULL)
		width_len--;
	if (width_len > 0)
	{
		width = ft_strgen(' ', width_len);
		f->tostring = f->flags[1] == '-' ?
			ft_strjoinfree(f->tostring, width) :
			ft_strjoinfree(width, f->tostring);
	}
	ft_width_tostring_more(f);
}
