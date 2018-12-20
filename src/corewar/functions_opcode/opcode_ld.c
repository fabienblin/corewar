/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_ld.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 09:44:53 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:45:41 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_ld(t_var *data, unsigned int pc)
{
	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;
	unsigned char	p_4;
	unsigned char	test;

	test = '\0';
	p_1 = data->vm[pc + 1] >> 6;
	p_2 = (unsigned char)(0x3 & (data->vm[pc + 1] >> 4));
	p_3 = (unsigned char)(0x3 & (data->vm[pc + 1] >> 2));
	p_4 = (unsigned char)(0x3 & data->vm[pc + 1]);
	if (p_1 == DIR_CODE)
		test = p_1;
	else if (p_1 == IND_CODE)
		test = p_1;
	if (!(test) || !(p_2 & REG_CODE) || p_3 || p_4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_ld(t_var *data, t_process *p_process)
{
	if (!check_ld(data, p_process->pc) && !ft_params_opcode(data, p_process, 4, 1))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | ld %i r%i\n", p_process->id, data->t_params[0][0], data->t_params[1][1]);
		p_process->registre[data->t_params[1][1]].val =	data->t_params[0][0];
		if (p_process->registre[data->t_params[1][1]].val == 0)
			p_process->carry = 1;
		else
			p_process->carry = 0;
		p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}