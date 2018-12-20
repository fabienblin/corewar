/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_sti.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:06:14 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:46:30 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_sti(t_var *data, unsigned int pc)
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
	if (p_3 == REG_CODE)
		test = p_3;
	else if (p_3 == DIR_CODE)
		test = p_3;
	if (!(p_1 & REG_CODE) || !(p_2 & 0x3) || !(test) || p_4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_sti(t_var *data, t_process *p_process)
{
	unsigned int	tmp_adr;
	unsigned char	tmp_val[4];
	int 			i;

	if (!check_sti(data, p_process->pc) && !ft_params_opcode(data, p_process, 2, 0))
	{
		tmp_adr = ((p_process->pc + (short)data->t_params[0][1] + (short)data->t_params[0][2]) % MEM_SIZE);
		tmp_val[0] = (unsigned char)((data->t_params[0][0]) >> 24);
		tmp_val[1] = (unsigned char)((data->t_params[0][0]) >> 16);
		tmp_val[2] = (unsigned char)((data->t_params[0][0]) >> 8);
		tmp_val[3] = (unsigned char)(data->t_params[0][0]);
		i = 0;
		while (i < REG_SIZE)
		{
			data->vm[(tmp_adr + i) % MEM_SIZE] = tmp_val[i];
			i++;
		}
		if (data->v == 4 || data->v == 6)
		{
			ft_printf("P %4i | sti r%i %i %i\n", p_process->id,
					  (short)data->t_params[1][0], (short)data->t_params[0][1],
					  data->t_params[0][2]);
			ft_printf("       | -> store to %i + %i = %i (with pc and mod %i)\n",
					  (short)data->t_params[0][1], (short)data->t_params[0][2],
					  ((short)data->t_params[0][1] + (short)data->t_params[0][2]), tmp_adr);
		}
		p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc =  ((p_process->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}