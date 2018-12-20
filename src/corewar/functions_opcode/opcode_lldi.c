/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_lldi.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 09:55:47 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:46:11 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_lldi(t_var *data, unsigned int pc)
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
	if (p_2 == REG_CODE)
		test = p_2;
	else if (p_2 == DIR_CODE)
		test = p_2;
	if (!(p_1 & 0x3) || !(test) || !(p_3 & REG_CODE) || p_4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_lldi(t_var *data, t_process *p_process)
{
	unsigned int	tmp_adr;

	if (!check_lldi(data, p_process->pc) && !ft_params_opcode(data, p_process, 2, 0))
	{
		tmp_adr = (data->t_params[0][0] + data->t_params[0][1]);
		p_process->registre[data->t_params[1][2]].val =
				((data->vm[(p_process->pc + tmp_adr) % MEM_SIZE] << 24)
				 +  (data->vm[(p_process->pc + tmp_adr + 1) % MEM_SIZE] << 16)
				 + (data->vm[(p_process->pc + tmp_adr + 2) % MEM_SIZE] << 8)
				 + (data->vm[(p_process->pc + tmp_adr + 3) % MEM_SIZE]));
		if (data->v == 4 || data->v == 6)
		{
			ft_printf("P %4i | lldi %i %i r%i\n", p_process->id,
					  data->t_params[0][0], data->t_params[0][1],
					  data->t_params[1][2]);
			ft_printf("       | -> load from %i + %i = %i (with pc %i)\n",
					  data->t_params[0][0], data->t_params[0][1],
					  (data->t_params[0][0] + data->t_params[0][1]),
					  (p_process->pc + tmp_adr));
		}
		if (p_process->registre[data->t_params[1][2]].val == 0)
			p_process->carry = 1;
		else
			p_process->carry = 0;
		p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc =  ((p_process->pc + 1) % MEM_SIZE);
	return (EXIT_FAILURE);
}