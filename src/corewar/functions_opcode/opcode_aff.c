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
	size_t 			i;

	i = 0;
	p[i] = data->vm[((pc + 1) % MEM_SIZE)] >> 6;
	data->op_size += 1;
	while (i < 1)
	{
		if (p[i] == REG_CODE)
			data->op_size += 1;
		else if (p[i] == DIR_CODE)
			dir_oct == 2 ? (data->op_size += 2) : (data->op_size += 4);
		else if (p[i] == IND_CODE)
			data->op_size += 2;
		i++;
	}
	if (p[0] != REG_CODE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_aff(t_var *data, t_process *p_process)
{
	if (!check_aff(data, p_process->pc, 4) && !ft_params_opcode(data, p_process, 4, 1))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i| aff %c\n", p_process->id, (data->t_params[0][0] % 256));
		p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}
