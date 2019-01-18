/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_o.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 09:52:17 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_to_str(t_data *data)
{
	if (!data->diese || !data->argument)
	{
		data->s_con = ft_strdup("");
		data->l_con = 0;
	}
	else
	{
		data->s_con = ft_strdup("0");
		data->l_con = 1;
	}
	if (data->largeur && !data->argument && data->precision == 1)
		data->s_val = ft_strdup("0");
	else if (data->largeur && !data->argument && data->point
		&& data->precision == 0)
		data->s_val = ft_strdup(" ");
	else if (!data->diese && data->precision == 0 && !data->argument)
		data->s_val = ft_strdup("");
	else
		data->s_val = ft_uitoa_base(data->argument, BASE_8);
	data->l_val = ft_strlen(data->s_val);
	return (0);
}

static int	ft_to_precision(t_data *data)
{
	int		ecart;

	data->l_pre = 0;
	ecart = data->precision - data->l_val - data->l_con;
	if (data->point && ecart > 0)
	{
		data->s_pre = ft_strnew(ecart);
		data->s_pre = ft_memset(data->s_pre, '0', ecart);
		data->l_pre = ecart;
	}
	else
		data->s_pre = ft_strnew(0);
	return (0);
}

static int	ft_to_largeur(t_data *data)
{
	int		ecart;
	char	c;

	c = ' ';
	data->l_lar = 0;
	ecart = data->largeur - data->l_val - data->l_pre - data->l_con;
	if (data->zero && !data->moin && !data->point)
		c = '0';
	if (ecart > 0)
	{
		data->s_lar = ft_strnew(ecart);
		data->s_lar = ft_memset(data->s_lar, c, ecart);
		data->l_lar = ecart;
	}
	else if (ecart <= 0)
		data->s_lar = ft_strnew(0);
	return (0);
}

static int	ft_join(t_data *d)
{
	char	*arg;
	char	*tmp;

	tmp = NULL;
	arg = ft_strjoin(d->s_pre, d->s_val);
	if (d->moin)
		tmp = ft_strjoin(d->s_con, arg);
	if (d->moin)
		d->s_arg = ft_strjoin(tmp, d->s_lar);
	else
	{
		if (!d->zero || d->point)
			tmp = ft_strjoin(d->s_lar, d->s_con);
		else if (d->zero && !d->point)
			tmp = ft_strjoin(d->s_con, d->s_lar);
		d->s_arg = ft_strjoin(tmp, arg);
	}
	d->l_arg = d->l_con + d->l_lar + d->l_pre + d->l_val;
	free(arg);
	free(tmp);
	tmp = d->s_pri;
	d->s_pri = ft_memjoin(d->s_pri, d->l_pri, d->s_arg, d->l_arg);
	d->l_pri = d->l_pri + d->l_arg;
	free(tmp);
	return (0);
}

int			ft_o(t_data *data)
{
	ft_to_str(data);
	ft_to_precision(data);
	ft_to_largeur(data);
	ft_join(data);
	free(data->s_con);
	data->l_con = 0;
	free(data->s_val);
	data->l_val = 0;
	free(data->s_pre);
	data->l_pre = 0;
	free(data->s_lar);
	data->l_lar = 0;
	free(data->s_arg);
	data->l_arg = 0;
	return (0);
}
