/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags_tostring.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 15:11:58 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 13:41:54 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag_hashtag_tostring(t_format *f)
{
	char	*tmp;

	tmp = NULL;
	if ((f->type == 'o' || f->type == 'O') && f->tostring[0] != '0')
		f->tostring = ft_strjoinfree(ft_strdup("0"), f->tostring);
	else if (((f->type == 'x' || f->type == 'X') && ft_strcmp(f->arg, "0")) ||
			f->type == 'p')
	{
		tmp = ft_strgen('0', 2);
		tmp[1] = 'X';
		f->tostring = ft_strjoinfree(tmp, f->tostring);
	}
}

static void	ft_flag_plus_tostring(t_format *f)
{
	if (!ft_strchr(f->tostring, '-') &&
	(f->type == 'd' || f->type == 'D' || f->type == 'i') &&
	f->flags[0] == '+')
	{
		f->tostring = ft_strjoinfree(ft_strdup("+"), f->tostring);
	}
}

static void	ft_flag_space_tostring(t_format *f)
{
	if (!ft_strchr(f->arg, '-') &&
		(f->type == 'd' || f->type == 'D' || f->type == 'i') &&
		f->flags[4] == ' ' && f->tostring[0] != ' ')
		f->tostring = ft_strjoinfree(ft_strdup(" "), f->tostring);
}

static void	ft_flag_zero_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;

	tmp_len = f->width - ft_strlen(f->tostring);
	if (f->width > 0 && f->preci > 0 && f->width > f->preci && f->type != '%')
		tmp_len -= f->width - f->preci;
	if (f->flags[3] == '#' && (ft_strcmp("0", f->arg) || f->type == 'p'))
		tmp_len -= 2;
	if (f->flags[4] == ' ' && f->tostring[0] != ' ')
		tmp_len -= 1;
	if ((f->type == 'c' || f->type == 'C') && f->arg == 0)
		tmp_len -= 1;
	if (f->preci == 0)
		tmp_len = 0;
	if (tmp_len > 0)
	{
		tmp = ft_strgen('0', tmp_len);
		f->tostring = ft_strjoinfree(tmp, f->tostring);
	}
}

void		ft_flags_tostring(t_format *f)
{
	if (f->flags[0] == '+')
		ft_flag_plus_tostring(f);
	if (f->flags[1] == '-')
		;
	if (f->flags[2] == '0')
		ft_flag_zero_tostring(f);
	if (f->flags[3] == '#')
		ft_flag_hashtag_tostring(f);
	if (f->flags[4] == ' ')
		ft_flag_space_tostring(f);
}
