/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conversion.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/22 10:36:57 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_c_s_p_pourcent(t_data *data, va_list *argv)
{
	if (data->type == C)
	{
		if (data->taille == DEF_TAI)
			data->argument = (int)va_arg(*argv, intmax_t);
		else if (data->taille == L)
			data->argument = (wint_t)va_arg(*argv, intmax_t);
	}
	else if (data->type == S)
	{
		if (data->taille == DEF_TAI)
			data->argument = (intmax_t)va_arg(*argv, char *);
		else if (data->taille == L)
			data->argument = (intmax_t)va_arg(*argv, wchar_t *);
	}
	else if (data->type == P)
		data->argument = (intmax_t)va_arg(*argv, void*);
	else if (data->type == POURCENT)
		data->argument = '%';
	return (0);
}

static int		ft_signed_integer(t_data *data, va_list *argv)
{
	if (data->taille == HH)
		data->argument = (signed char)va_arg(*argv, intmax_t);
	else if (data->taille == H)
		data->argument = (short)va_arg(*argv, intmax_t);
	else if (data->taille == DEF_TAI)
		data->argument = (int)va_arg(*argv, intmax_t);
	else if (data->taille == L)
		data->argument = (long)va_arg(*argv, intmax_t);
	else if (data->taille == LL)
		data->argument = (long long)va_arg(*argv, intmax_t);
	else if (data->taille == J)
		data->argument = (intmax_t)va_arg(*argv, intmax_t);
	else if (data->taille == Z)
		data->argument = (ssize_t)va_arg(*argv, intmax_t);
	return (0);
}

static int		ft_unsigned_integer(t_data *data, va_list *argv)
{
	if (data->taille == HH)
		data->argument = (unsigned char)va_arg(*argv, uintmax_t);
	else if (data->taille == H)
		data->argument = (unsigned short)va_arg(*argv, uintmax_t);
	else if (data->taille == DEF_TAI)
		data->argument = (unsigned int)va_arg(*argv, uintmax_t);
	else if (data->taille == L)
		data->argument = (unsigned long)va_arg(*argv, uintmax_t);
	else if (data->taille == LL)
		data->argument = (unsigned long long)va_arg(*argv, uintmax_t);
	else if (data->taille == J)
		data->argument = (intmax_t)va_arg(*argv, uintmax_t);
	else if (data->taille == Z)
		data->argument = (ssize_t)va_arg(*argv, uintmax_t);
	return (0);
}

static int		ft_n_pointer(t_data *data, va_list *argv)
{
	int		*rep;
	int		val;

	val = (int)data->l_pri;
	rep = &val;
	if (data->taille == HH)
		*va_arg(*argv, char *) = data->l_pri;
	else if (data->taille == H)
		*va_arg(*argv, short *) = data->l_pri;
	else if (data->taille == DEF_TAI)
		*va_arg(*argv, int *) = *rep;
	else if (data->taille == L)
		*va_arg(*argv, long *) = data->l_pri;
	else if (data->taille == LL)
		*va_arg(*argv, long long *) = data->l_pri;
	else if (data->taille == J)
		*va_arg(*argv, intmax_t *) = data->l_pri;
	else if (data->taille == Z)
		*va_arg(*argv, size_t *) = data->l_pri;
	return (0);
}

int				ft_conversion(t_data *data, va_list *argv)
{
	if (data->type == S || data->type == C || data->type == P
			|| data->type == POURCENT)
		ft_c_s_p_pourcent(data, argv);
	else if (data->type == D || data->type == I)
		ft_signed_integer(data, argv);
	else if (data->type == O || data->type == U || data->type == X
			|| data->type == LX || data->type == B)
		ft_unsigned_integer(data, argv);
	else if (data->type == N)
		ft_n_pointer(data, argv);
	return (0);
}
