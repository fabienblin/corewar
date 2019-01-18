/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_st.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:04:04 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 10:04:04 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_st(t_var *data, unsigned int pc, int dir_oct)
{
	unsigned char	p[2];
	unsigned char	test;
	long			i;

	i = -1;
	test = '\0';
	p[0] = data->vm[((pc + 1) % MEM_SIZE)] >> 6;
	p[1] = (unsigned char)(0x3 & (data->vm[((pc + 1) % MEM_SIZE)] >> 4));
	data->op_size += 1;
	while (++i < 2)
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
	else if (p[1] == IND_CODE)
		test = p[1];
	if ((p[0] != REG_CODE) || !(test))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void		opcode_st_2(t_var *data, t_process *p_proc,
									unsigned char *tmp_val, long *i)
{
	tmp_val[0] = p_proc->registre[data->t_params[1][0]].val >> 24;
	tmp_val[1] = p_proc->registre[data->t_params[1][0]].val >> 16;
	tmp_val[2] = p_proc->registre[data->t_params[1][0]].val >> 8;
	tmp_val[3] = p_proc->registre[data->t_params[1][0]].val;
	*i = 0;
	while (*i < REG_SIZE)
	{
		data->vm[((p_proc->pc + (data->t_params[0][1] % IDX_MOD) + *i))
			% MEM_SIZE] = tmp_val[*i];
		*i = *i + 1;
	}
	if (data->v == 4 || data->v == 6)
		ft_printf("P %4i | st r%i %i\n", p_proc->id,
			data->t_params[1][0], data->t_params[0][1]);
}

int				opcode_st(t_var *data, t_process *p_proc)
{
	unsigned char	tmp_val[4];
	long			i;

	if (!check_st(data, p_proc->pc, 4) && !ft_params_opcode(data, p_proc, 4, 0))
	{
		if (data->t_params[1][1] == 0)
		{
			opcode_st_2(data, p_proc, tmp_val, &i);
		}
		else
		{
			p_proc->registre[data->t_params[1][1]].val =
					p_proc->registre[data->t_params[1][0]].val;
			if (data->v == 4 || data->v == 6)
				ft_printf("P %4i | st r%i %i\n", p_proc->id,
					data->t_params[1][0], data->t_params[1][1]);
		}
		p_proc->pc = ((p_proc->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_proc->pc = ((p_proc->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}
