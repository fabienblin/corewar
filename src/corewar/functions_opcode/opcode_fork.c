/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_fork.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 09:42:43 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:45:37 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				opcode_fork(t_var *data, t_process *p_process, int i)
{
	if (!ft_params_opcode(data, p_process, 2, 0))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | fork %hi (%hi)\n", p_process->id,
			data->t_params[0][0],
			p_process->pc + ((short)data->t_params[0][0] % IDX_MOD));
		t_process_create(data, p_process, i, 1);
		p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc = ((p_process->pc + 1) % MEM_SIZE);
	return (EXIT_FAILURE);
}