/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_xor.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:09:36 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 10:09:36 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_xor(t_var *data, unsigned int pc, int dir_oct)
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

int				opcode_xor(t_var *data, t_process *p_process)
{
	if (!check_xor(data, p_process->pc, 4)
		&& !ft_params_opcode(data, p_process, 4, 1))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | xor %i %i r%i\n", p_process->id,
			data->t_params[0][0], data->t_params[0][1], data->t_params[1][2]);
		p_process->registre[data->t_params[1][2]].val =
				(data->t_params[0][0] ^ data->t_params[0][1]);
		p_process->registre[data->t_params[1][2]].val =
				data->t_params[0][0] ^ data->t_params[0][1];
		if (p_process->registre[data->t_params[1][2]].val == 0)
			p_process->carry = 1;
		else
			p_process->carry = 0;
		p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}
