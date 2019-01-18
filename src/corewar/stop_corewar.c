/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stop_corewar.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 09:11:18 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 09:11:18 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				stop_corewar(t_var *data)
{
	unsigned long	nb_process;
	t_process		*p_process;

	nb_process = 0;
	p_process = data->lst_process;
	while (p_process)
	{
		if (data->lst_process)
			nb_process++;
		p_process = p_process->next;
	}
	if (nb_process == 0 || (long)data->check_cycle_delta < 0)
		data->stop_corewar = 1;
	return (EXIT_SUCCESS);
}
