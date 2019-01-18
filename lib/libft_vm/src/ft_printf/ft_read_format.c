/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_format.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 17:57:51 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_init_data(t_data *data)
{
	data->diese = 0;
	data->zero = 0;
	data->moin = 0;
	data->pluss = 0;
	data->espace = 0;
	data->largeur = 0;
	data->point = 0;
	data->precision = 1;
	data->taille = 0;
	data->type = 0;
	data->argument = 0;
	return (0);
}

int				ft_read_format(t_data *data, va_list *argv)
{
	ft_av_format(data, 1);
	while (data->type == DEF_TYP && *data->s_for != '\0')
	{
		if (ft_strchr(TYPE, *data->s_for))
			ft_read_type(data);
		else if (ft_strchr(FLAG, *data->s_for))
			ft_read_flag(data);
		else if (ft_strchr(LARGEUR, *data->s_for))
			ft_read_largeur(data, argv);
		else if (ft_strchr(PRECISION, *data->s_for))
			ft_read_precision(data, argv);
		else if (ft_strchr(TAILLE, *data->s_for))
			ft_read_taille(data);
		else
		{
			data->argument = *data->s_for;
			data->type = CC;
		}
		ft_av_format(data, 1);
	}
	return (0);
}
