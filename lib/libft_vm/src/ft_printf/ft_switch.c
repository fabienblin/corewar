/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_switch.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:09:16 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_switch(t_data *data)
{
	int		ret;

	data->type == S ? (ret = ft_s(data)) : 0;
	data->type == C || data->type == CC ? (ret = ft_c(data)) : 0;
	data->type == P ? (ret = ft_p(data)) : 0;
	data->type == D || data->type == I ? (ret = ft_d_i(data)) : 0;
	data->type == U ? (ret = ft_u(data)) : 0;
	data->type == O ? (ret = ft_o(data)) : 0;
	data->type == X ? (ret = ft_x(data)) : 0;
	data->type == LX ? (ret = ft_lx(data)) : 0;
	data->type == B ? (ret = ft_b(data)) : 0;
	data->type == N ? (ret = ft_n(data)) : 0;
	data->type == POURCENT ? (ret = ft_pourcent(data)) : 0;
	return (ret);
}
