/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_lfork.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 09:59:14 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 09:59:14 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				opcode_lfork(t_var *data, t_process *p_process)
{
	if (!ft_params_opcode(data, p_process, 2, 0))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | lfork %hi (%hi)\n", p_process->id,
			data->t_params[0][0],
			p_process->pc + ((short)data->t_params[0][0]));
		t_process_create(data, p_process, 0);
		p_process->pc = ((p_process->pc + 3) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc = ((p_process->pc + 3) % MEM_SIZE);
	return (EXIT_FAILURE);
}
