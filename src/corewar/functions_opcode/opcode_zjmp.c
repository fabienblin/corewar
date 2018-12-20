/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_zjmp.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:11:07 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:46:48 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				opcode_zjmp(t_var *data, t_process *p_process)
{
	if (!ft_params_opcode(data, p_process, 2, 0))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | zjmp %hi", p_process->id,
					(short)data->t_params[0][0]);
		if (p_process->carry == 1)
		{
			if (data->v == 4 || data->v == 6)
				ft_printf(" OK\n");
			p_process->pc = ((p_process->pc + (short)data->t_params[0][0]) % MEM_SIZE);
			return (EXIT_SUCCESS);
		}
		else
		{
			if (data->v == 4 || data->v == 6)
				ft_printf(" FAILED\n");
			p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
			return (EXIT_SUCCESS);
		}
	}
	p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}