/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gestion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 11:43:28 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_init(const char *format, t_data *data)
{
	data->s_for = (char *)format;
	data->l_for = 0;
	data->s_pri = ft_strnew(0);
	data->l_pri = 0;
	data->pos = 0;
	data->ret = 0;
	return (0);
}

int			ft_av_format(t_data *data, unsigned int i)
{
	data->s_for += i;
	data->l_for += i;
	return (0);
}

int			ft_add_caractere(t_data *data)
{
	char	*tmp_c;
	char	*tmp_str;

	if ((tmp_c = ft_strnew(1)) == NULL)
		return (-1);
	tmp_c[0] = *data->s_for;
	if ((tmp_str = ft_memjoin(data->s_pri, data->l_pri, tmp_c, 1)) == NULL)
		return (-1);
	free(tmp_c);
	free(data->s_pri);
	data->s_pri = tmp_str;
	data->l_pri += 1;
	ft_av_format(data, 1);
	return (0);
}
