/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_aff.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 20:04:58 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:45:28 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_aff(t_var *data, unsigned int pc)
{
	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;
	unsigned char	p_4;

	p_1 = data->vm[pc + 1] >> 6;
	p_2 = (unsigned char)(0x3 & (data->vm[pc + 1] >> 4));
	p_3 = (unsigned char)(0x3 & (data->vm[pc + 1] >> 2));
	p_4 = (unsigned char)(0x3 & data->vm[pc + 1]);
	if (!(p_1 & REG_CODE) || p_2 || p_3 || p_4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_aff(t_var *data, t_process *p_process)
{
	if (!check_aff(data, p_process->pc) && !ft_params_opcode(data, p_process, 0, 1))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i| aff %c\n", p_process->id, (data->t_params[0][0] % 256));
		p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc =  ((p_process->pc + 1) % MEM_SIZE);
	return (EXIT_FAILURE);
}
