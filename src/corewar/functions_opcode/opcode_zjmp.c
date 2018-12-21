/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_zjmp.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:11:07 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 10:11:07 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				opcode_zjmp(t_var *data, t_process *p_process)
{
	int	val;

	if (!ft_params_opcode(data, p_process, 2, 0))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | zjmp %hi", p_process->id,
					(short)data->t_params[0][0]);
		if (p_process->carry == 1)
		{
			if (data->v == 4 || data->v == 6)
				ft_printf(" OK\n");
			val = ((p_process->pc + ((short)data->t_params[0][0] % IDX_MOD)) % MEM_SIZE);
			//if (val < 0)
			//	val = MEM_SIZE - p_process->pc;
			p_process->pc = val;
			return (EXIT_SUCCESS);
		}
		else
		{
			if (data->v == 4 || data->v == 6)
				ft_printf(" FAILED\n");
			p_process->pc = ((p_process->pc + 3) % MEM_SIZE);
			return (EXIT_SUCCESS);
		}
	}
	p_process->pc = ((p_process->pc + 3) % MEM_SIZE);
	return (EXIT_FAILURE);
}