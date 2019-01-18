/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_lldi.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 09:55:47 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 09:55:47 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void		check_lldi_2(long *i, unsigned char *test)
{
	*i = -1;
	*test = '\0';
}

static int		check_lldi(t_var *data, unsigned int pc, int dir_oct)
{
	unsigned char	p[3];
	unsigned char	test;
	long			i;

	check_lldi_2(&i, &test);
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
	if (p[1] == REG_CODE)
		test = p[1];
	else if (p[1] == DIR_CODE)
		test = p[1];
	if (!(p[0] & 0x3) || !(test) || (p[2] != REG_CODE))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void		opcode_lldi_2(t_var *data, t_process *p_process,
								unsigned int tmp_adr)
{
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
}

int				opcode_lldi(t_var *data, t_process *proc)
{
	unsigned int	tmp_adr;

	if (!check_lldi(data, proc->pc, 2) && !ft_params_opcode(data, proc, 2, 0))
	{
		tmp_adr = (data->t_params[0][0] + data->t_params[0][1]);
		proc->registre[data->t_params[1][2]].val =
			((data->vm[(proc->pc + tmp_adr) % MEM_SIZE] << 24)
			+ (data->vm[(proc->pc + tmp_adr + 1) % MEM_SIZE] << 16)
			+ (data->vm[(proc->pc + tmp_adr + 2) % MEM_SIZE] << 8)
			+ (data->vm[(proc->pc + tmp_adr + 3) % MEM_SIZE]));
		opcode_lldi_2(data, proc, tmp_adr);
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
