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

int				opcode_zjmp(t_var *d, t_process *proc)
{
	int	val;

	if (!ft_params_opcode(d, proc, 2, 0))
	{
		if (d->v == 4 || d->v == 6)
			ft_printf("P %4i | zjmp %hi", proc->id, (short)d->t_params[0][0]);
		if (proc->carry == 1)
		{
			if (d->v == 4 || d->v == 6)
				ft_printf(" OK\n");
			val = ((proc->pc +
				((short)d->t_params[0][0] % IDX_MOD)) % MEM_SIZE);
			proc->pc = val;
			return (EXIT_SUCCESS);
		}
		else
		{
			if (d->v == 4 || d->v == 6)
				ft_printf(" FAILED\n");
			proc->pc = ((proc->pc + 3) % MEM_SIZE);
			return (EXIT_SUCCESS);
		}
	}
	proc->pc = ((proc->pc + 3) % MEM_SIZE);
	return (EXIT_FAILURE);
}
