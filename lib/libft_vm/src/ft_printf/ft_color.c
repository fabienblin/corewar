/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 12:44:01 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_color_2(t_data *d)
{
	int		size;

	size = 0;
	!ft_strncmp(d->s_for, "{red}", 5) ? size = 5 : 0;
	!ft_strncmp(d->s_for, "{green}", 7) ? size = 7 : 0;
	!ft_strncmp(d->s_for, "{yellow}", 8) ? size = 8 : 0;
	!ft_strncmp(d->s_for, "{blue}", 6) ? size = 6 : 0;
	!ft_strncmp(d->s_for, "{magenta}", 9) ? size = 9 : 0;
	!ft_strncmp(d->s_for, "{cyan}", 6) ? size = 6 : 0;
	!ft_strncmp(d->s_for, "{white}", 7) ? size = 7 : 0;
	!ft_strncmp(d->s_for, "{eoc}", 5) ? size = 5 : 0;
	return (size);
}

int				ft_color(t_data *d)
{
	char	*tmp;
	char	*c;
	int		size;

	c = NULL;
	!ft_strncmp(d->s_for, "{red}", 5) ? c = "\x1B[31m" : 0;
	!ft_strncmp(d->s_for, "{green}", 7) ? c = "\x1B[32m" : 0;
	!ft_strncmp(d->s_for, "{yellow}", 8) ? c = "\x1B[33m" : 0;
	!ft_strncmp(d->s_for, "{blue}", 6) ? c = "\x1B[34m" : 0;
	!ft_strncmp(d->s_for, "{magenta}", 9) ? c = "\x1B[35m" : 0;
	!ft_strncmp(d->s_for, "{cyan}", 6) ? c = "\x1B[36m" : 0;
	!ft_strncmp(d->s_for, "{white}", 7) ? c = "\x1B[37m" : 0;
	!ft_strncmp(d->s_for, "{eoc}", 5) ? c = "\x1B[00m" : 0;
	if (c == NULL)
	{
		ft_add_caractere(d);
		return (0);
	}
	size = ft_color_2(d);
	tmp = d->s_pri;
	d->s_pri = ft_memjoin(d->s_pri, d->l_pri, c, size);
	d->l_pri += 5;
	free(tmp);
	ft_av_format(d, size);
	return (0);
}
