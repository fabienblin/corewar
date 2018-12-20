/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_st.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:04:04 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:46:25 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_st(t_var *data, unsigned int pc)
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
	else if (p_2 == IND_CODE)
		test = p_2;
	if (!(p_1 & REG_CODE) || !(test) || p_3 || p_4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_st(t_var *data, t_process *p_process)
{

	unsigned char	tmp_val[4];
	int 			i;

	if (!check_st(data, p_process->pc) && !ft_params_opcode(data, p_process, 0, 1))
	{
		if (data->t_params[1][1] == 0)
		{
			tmp_val[0] = p_process->registre[data->t_params[1][0]].val >> 24;
			tmp_val[1] = p_process->registre[data->t_params[1][0]].val >> 16;
			tmp_val[2] = p_process->registre[data->t_params[1][0]].val >> 8;
			tmp_val[3] = p_process->registre[data->t_params[1][0]].val;
			i = 0;
			while (i < REG_SIZE)
			{
				data->vm[((p_process->pc + data->t_params[0][1] + i))
					% MEM_SIZE] = tmp_val[i];
				i++;
			}
			if (data->v == 4 || data->v == 6)
				ft_printf("P    %i | st r%i %i\n", p_process->id,
					data->t_params[1][0], data->t_params[0][1]);
		}
		else
		{
			p_process->registre[data->t_params[1][1]].val
				= p_process->registre[data->t_params[1][0]].val;
			if (data->v == 4 || data->v == 6)
				ft_printf("P %4i | st r%i %i\n", p_process->id,
					data->t_params[1][0], data->t_params[1][1]);
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