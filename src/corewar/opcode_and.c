/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_and.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 20:13:51 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 20:13:51 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_and(t_var *data, unsigned int pc, int dir_oct)
{
	unsigned char	p[3];
	long			i;

	i = -1;
	p[0] = data->vm[((pc + 1) % MEM_SIZE)] >> 6;
	p[1] = (unsigned char)(0x3 & (data->vm[((pc + 1) % MEM_SIZE)] >> 4));
	p[2] = (unsigned char)(0x3 & (data->vm[((pc + 1) % MEM_SIZE)] >> 2));
	data->op_size += 1;
	while (++i < 3)
	{
		if (p[i] == REG_CODE)
			data->op_size += 1;
		else if (p[i] == DIR_CODE)
			dir_oct == 2 ? (data->op_size += 2) : (data->op_size += 4);
		else if (p[i] == IND_CODE)
			data->op_size += 2;
	}
	if (!(p[0] & 0x3) || !(p[1] & 0x3) || (p[2] != REG_CODE))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_and(t_var *data, t_process *proc)
{
	if (!check_and(data, proc->pc, 4) && !ft_params_opcode(data, proc, 4, 1))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | and %i %i r%i\n", proc->id,
			data->t_params[0][0], data->t_params[0][1], data->t_params[1][2]);
		proc->registre[data->t_params[1][2]].val = (data->t_params[0][0]
			& data->t_params[0][1]);
		if (proc->registre[data->t_params[1][2]].val == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		proc->pc = ((proc->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	proc->pc = ((proc->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}
