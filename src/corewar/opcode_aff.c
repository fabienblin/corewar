/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_aff.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 20:04:58 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 20:04:58 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_aff(t_var *data, unsigned int pc, int dir_oct)
{
	unsigned char	p[1];
	long			i;

	i = -1;
	p[0] = data->vm[((pc + 1) % MEM_SIZE)] >> 6;
	data->op_size += 1;
	while (++i < 1)
	{
		if (p[i] == REG_CODE)
			data->op_size += 1;
		else if (p[i] == DIR_CODE)
			dir_oct == 2 ? (data->op_size += 2) : (data->op_size += 4);
		else if (p[i] == IND_CODE)
			data->op_size += 2;
	}
	if (p[0] != REG_CODE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_aff(t_var *data, t_process *proc)
{
	if (!check_aff(data, proc->pc, 4) && !ft_params_opcode(data, proc, 4, 1))
	{
		if (data->v == 0)
			ft_printf("%d\n", data->t_params[0][0] % 256);
		proc->pc = ((proc->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	proc->pc = ((proc->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}
