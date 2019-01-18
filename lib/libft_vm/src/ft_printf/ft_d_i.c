/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_d_i.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 10:31:06 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_to_signe(t_data *data)
{
	data->s_sig = ft_strnew(1);
	data->l_sig = 1;
	*data->s_sig = '+';
	if (data->argument < 0)
	{
		data->argument = -data->argument;
		*data->s_sig = '-';
		return (0);
	}
	if (data->pluss)
		return (0);
	else if (data->espace && *data->s_sig == '+')
		*data->s_sig = ' ';
	else if (!data->espace && !data->pluss && *data->s_sig == '+')
	{
		*data->s_sig = '\0';
		data->l_sig = 0;
	}
	return (0);
}

static int	ft_to_str(t_data *data)
{
	int		ecart;

	if (!data->zero && data->largeur && data->precision == 1 && !data->argument)
		data->s_val = ft_strdup("0");
	else if (!data->zero && data->largeur && !data->argument)
		data->s_val = ft_strdup(" ");
	else if (!data->diese && data->precision == 0 && !data->argument)
		data->s_val = ft_strdup("");
	else
		data->s_val = ft_uitoa_base(data->argument, BASE_10);
	data->l_val = ft_strlen(data->s_val);
	data->l_pre = 0;
	ecart = data->precision - data->l_val;
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
	data->moin = (data->largeur < 0) ? 1 : data->moin;
	data->largeur = (data->largeur < 0) ? -data->largeur : data->largeur;
	ecart = data->largeur - data->l_val - data->l_pre - data->l_sig;
	if (data->precision < 0)
		data->point = 0;
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
		tmp = ft_strjoin(d->s_sig, arg);
	if (d->moin)
		d->s_arg = ft_strjoin(tmp, d->s_lar);
	else
	{
		if (!d->zero || d->point)
			tmp = ft_strjoin(d->s_lar, d->s_sig);
		else if (d->zero && !d->point)
			tmp = ft_strjoin(d->s_sig, d->s_lar);
		d->s_arg = ft_strjoin(tmp, arg);
	}
	d->l_arg = d->l_sig + d->l_lar + d->l_pre + d->l_val;
	free(arg);
	free(tmp);
	tmp = d->s_pri;
	d->s_pri = ft_memjoin(d->s_pri, d->l_pri, d->s_arg, d->l_arg);
	d->l_pri = d->l_pri + d->l_arg;
	free(tmp);
	return (0);
}

int			ft_d_i(t_data *data)
{
	ft_to_signe(data);
	ft_to_str(data);
	ft_to_largeur(data);
	ft_join(data);
	free(data->s_sig);
	data->l_sig = 0;
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
