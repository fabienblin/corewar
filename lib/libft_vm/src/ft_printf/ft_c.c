/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_c.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 19:31:54 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_to_str(t_data *data)
{
	if (data->type == CC)
		data->taille = DEF_TAI;
	if (data->taille == DEF_TAI)
	{
		data->s_val = ft_strnew(1);
		data->l_val = 1;
		if (data->argument != 0)
			data->s_val[0] = data->argument;
		else
			data->s_val[0] = '\0';
	}
	else if (data->taille == L)
	{
		data->s_val = ft_w_char(data);
		data->l_val = ft_strlen(data->s_val);
		if (data->l_val == 0)
			data->l_val = 1;
		if ((MB_CUR_MAX == 1 && data->argument > 255)
			|| (MB_CUR_MAX != 1
			&& (data->argument > 0x10ffff || data->argument < 0
			|| (data->argument > 0xd7ff && data->argument < 0xe000))))
			return (-1);
	}
	return (0);
}

static int		ft_to_largeur(t_data *data)
{
	int		ecart;
	char	c;

	c = ' ';
	data->l_lar = 0;
	data->moin = (data->largeur < 0) ? 1 : data->moin;
	data->largeur = (data->largeur < 0) ? -data->largeur : data->largeur;
	ecart = data->largeur - data->l_val;
	if (data->zero && (data->largeur || (!data->moin && !data->precision)))
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

static int		ft_join(t_data *data)
{
	char	*tmp;

	tmp = data->s_pri;
	data->s_arg = (data->moin) ?
		ft_memjoin(data->s_val, data->l_val, data->s_lar, data->l_lar)
		: ft_memjoin(data->s_lar, data->l_lar, data->s_val, data->l_val);
	data->l_arg = data->l_lar + data->l_val;
	data->s_pri =
		ft_memjoin(data->s_pri, data->l_pri, data->s_arg, data->l_arg);
	data->l_pri = data->l_pri + data->l_arg;
	free(tmp);
	return (0);
}

int				ft_c(t_data *data)
{
	int		ret;

	ret = ft_to_str(data);
	ft_to_largeur(data);
	ft_join(data);
	free(data->s_val);
	data->l_val = 0;
	free(data->s_lar);
	data->l_lar = 0;
	free(data->s_arg);
	data->l_arg = 0;
	return (ret);
}
