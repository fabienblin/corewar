/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_ldi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 09:47:47 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 09:47:47 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void		check_ldi_2(long *i, unsigned char *test)
{
	*i = -1;
	*test = '\0';
}

static int		check_ldi(t_var *data, unsigned int pc, int dir_oct)
{
	unsigned char	test;
	unsigned char	p[3];
	long			i;

	check_ldi_2(&i, &test);
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

int				opcode_ldi(t_var *d, t_process *proc)
{
	int	tmp_adr;

	if (!check_ldi(d, proc->pc, 2) && !ft_params_opcode(d, proc, 2, 1))
	{
		if (d->v == 4 || d->v == 6)
			ft_printf("P %4i | ldi %i %i r%i\n", proc->id,
				d->t_params[0][0], d->t_params[0][1], d->t_params[1][2]);
		tmp_adr = (d->t_params[0][0] +
				d->t_params[0][1]) % IDX_MOD;
		proc->registre[d->t_params[1][2]].val =
			((d->vm[(proc->pc + tmp_adr) % MEM_SIZE] << 24)
			+ (d->vm[(proc->pc + tmp_adr + 1) % MEM_SIZE] << 16)
			+ (d->vm[(proc->pc + tmp_adr + 2) % MEM_SIZE] << 8)
			+ (d->vm[(proc->pc + tmp_adr + 3) % MEM_SIZE]));
		if (d->v == 4 || d->v == 6)
			ft_printf("       | -> load from %i + %i = %i (with pc and mod %i)"
				"\n", d->t_params[0][0], d->t_params[0][1],
				(d->t_params[0][0] + d->t_params[0][1]),
				(proc->pc + tmp_adr) % MEM_SIZE);
		proc->pc = ((proc->pc + d->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	proc->pc = ((proc->pc + d->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}
