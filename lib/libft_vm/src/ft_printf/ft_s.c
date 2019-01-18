/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_s.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 19:31:54 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_to_str(t_data *data)
{
	data->largeur = (data->largeur < 0) ? -data->largeur : data->largeur;
	data->moin = (data->largeur < 0) ? 1 : data->moin;
	if (data->argument && data->taille == DEF_TAI)
		data->s_val = ft_strdup((const char*)data->argument);
	else if (data->argument && data->taille == L)
		data->s_val = ft_w_string(data);
	else
	{
		if (!data->argument)
			data->s_val = ft_strdup("(null)");
		else
			data->s_val = ft_strdup("\0");
	}
	data->l_val = (int)ft_strlen(data->s_val);
	if (data->ret == -1)
		return (-1);
	return (0);
}

static int	ft_to_precision(t_data *data)
{
	int		ecart;

	data->l_pre = 0;
	data->precision = (data->precision < 0) ?
		-data->precision : data->precision;
	ecart = data->precision - data->l_val;
	if (data->point && ecart < 0)
	{
		while ((data->s_val[data->precision] & 0xC0) == 0x80)
			data->precision--;
		data->s_val[data->precision] = '\0';
		data->l_val = (int)ft_strlen(data->s_val);
	}
	data->s_pre = ft_strnew(0);
	return (0);
}

static int	ft_to_largeur(t_data *data)
{
	int		ecart;
	char	c;

	c = ' ';
	data->l_lar = 0;
	ecart = data->largeur - data->l_val;
	if (data->zero &&
		(!data->moin && (data->largeur || !data->precision)))
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

static int	ft_join(t_data *data)
{
	char	*tmp;

	tmp = data->s_pri;
	data->s_arg = (data->moin) ?
		ft_strjoin(data->s_val, data->s_lar)
		: ft_strjoin(data->s_lar, data->s_val);
	data->l_arg = data->l_lar + data->l_val;
	data->s_pri =
		ft_memjoin(data->s_pri, data->l_pri, data->s_arg, data->l_arg);
	data->l_pri = data->l_pri + data->l_arg;
	free(tmp);
	return (0);
}

int			ft_s(t_data *data)
{
	int		ret;

	ret = ft_to_str(data);
	ft_to_precision(data);
	ft_to_largeur(data);
	ft_join(data);
	free(data->s_val);
	data->l_val = 0;
	free(data->s_pre);
	data->l_pre = 0;
	free(data->s_lar);
	data->l_lar = 0;
	free(data->s_arg);
	data->l_arg = 0;
	return (ret);
}
