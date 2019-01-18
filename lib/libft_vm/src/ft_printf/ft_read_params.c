/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 10:42:15 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_read_flag(t_data *data)
{
	if (*data->s_for == '#')
		data->diese = 1;
	else if (*data->s_for == '0')
		data->zero = 1;
	else if (*data->s_for == '-')
		data->moin = 1;
	else if (*data->s_for == '+')
		data->pluss = 1;
	else if (*data->s_for == ' ')
		data->espace = 1;
	return (0);
}

int				ft_read_largeur(t_data *data, va_list *argv)
{
	unsigned int	i;

	i = 0;
	if (*data->s_for == '*')
		data->largeur = (int)va_arg(*argv, intmax_t);
	else if (*data->s_for == '0')
		data->zero = 1;
	else if (*data->s_for >= '1' && *data->s_for <= '9')
	{
		while (*(data->s_for + i) >= '0' && *(data->s_for + i) <= '9')
			i++;
		data->largeur = ft_atoi(data->s_for);
		ft_av_format(data, i - 1);
	}
	return (0);
}

int				ft_read_precision(t_data *data, va_list *argv)
{
	unsigned int	i;

	i = 0;
	data->point = 1;
	data->precision = 0;
	if (*(data->s_for + 1) == '*')
	{
		data->precision = (int)va_arg(*argv, intmax_t);
		ft_av_format(data, 1);
	}
	else if (*(data->s_for + 1) >= '0' && *(data->s_for + 1) <= '9')
	{
		ft_av_format(data, 1);
		while (data->s_for[i] >= '0' && data->s_for[i] <= '9')
			i++;
		data->precision = ft_atoi(data->s_for);
		if (i > 0)
			ft_av_format(data, i - 1);
	}
	return (0);
}

int				ft_read_taille(t_data *data)
{
	t_taille	tmp;

	tmp = 0;
	if (*data->s_for == 'h' && *(data->s_for + 1) == 'h')
		tmp = HH;
	else if (*data->s_for == 'l' && *(data->s_for + 1) == 'l')
		tmp = LL;
	else if (*data->s_for == 'h')
		tmp = H;
	else if (*data->s_for == 'l')
		tmp = L;
	else if (*data->s_for == 'j')
		tmp = J;
	else if (*data->s_for == 'z')
		tmp = Z;
	if (tmp == HH || tmp == LL)
		ft_av_format(data, 1);
	if (tmp > data->taille)
		data->taille = tmp;
	return (0);
}

int				ft_read_type(t_data *data)
{
	*data->s_for == 's' || *data->s_for == 'S' ? data->type = S : 0;
	*data->s_for == 'c' || *data->s_for == 'C' ? data->type = C : 0;
	*data->s_for == 'p' ? data->type = P : 0;
	*data->s_for == '%' ? data->type = POURCENT : 0;
	*data->s_for == 'i' ? data->type = I : 0;
	*data->s_for == 'd' || *data->s_for == 'D' ? data->type = D : 0;
	*data->s_for == 'o' || *data->s_for == 'O' ? data->type = O : 0;
	*data->s_for == 'u' || *data->s_for == 'U' ? data->type = U : 0;
	*data->s_for == 'x' ? data->type = X : 0;
	*data->s_for == 'X' ? data->type = LX : 0;
	*data->s_for == 'b' ? data->type = B : 0;
	*data->s_for == 'n' ? data->type = N : 0;
	if (*data->s_for == 'S' || *data->s_for == 'C'
		|| *data->s_for == 'D' || *data->s_for == 'O'
		|| *data->s_for == 'U')
		data->taille = L;
	return (0);
}
