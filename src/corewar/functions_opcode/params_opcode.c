/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params_opcode.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 11:05:47 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 11:05:47 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_indirect(t_var *data, t_process *proc, int idx, int *n)
{
	short	val;

	val = (data->vm[(proc->pc + *n) % MEM_SIZE] << 8)
		+ (data->vm[(proc->pc + (*n + 1)) % MEM_SIZE]);
	//if (idx && data->vm[proc->pc] != 0x03)
	if (idx)
		val = val % IDX_MOD;
	if (proc->mem_op_code == 0x03)
		data->t_params[0][data->p_p] = val;
	else if (data->vm[proc->pc] == 0x0d)
	{
		data->t_params[0][data->p_p] =
				(data->vm[(proc->pc + val) % MEM_SIZE] << 8)
				+ data->vm[(proc->pc + val + 1) % MEM_SIZE];

	}
	else
		data->t_params[0][data->p_p] =
			(data->vm[(proc->pc + val) % MEM_SIZE] << 24)
			+ (data->vm[(proc->pc + val + 1) % MEM_SIZE] << 16)
			+ (data->vm[(proc->pc + val + 2) % MEM_SIZE] << 8)
			+ data->vm[(proc->pc + val + 3) % MEM_SIZE];
	data->p_p += 1;
	*n += 2;
	return (EXIT_SUCCESS);
}

static int	ft_direct(t_var *data, t_process *proc, int dir_oct, int *n)
{
	int	val;

	if (dir_oct == 2)
	{
		val = (data->vm[(proc->pc + *n) % MEM_SIZE] << 8)
			  + (data->vm[(proc->pc + (*n + 1)) % MEM_SIZE]);
		val = (short)val;
		*n += 2;
	}
	else
	{
		val = (data->vm[(proc->pc + *n) % MEM_SIZE] << 24)
			  + (data->vm[(proc->pc + (*n + 1)) % MEM_SIZE] << 16)
			  + (data->vm[(proc->pc + (*n + 2)) % MEM_SIZE] << 8)
			  + (data->vm[(proc->pc + (*n + 3)) % MEM_SIZE]);
		*n += 4;
	}
	data->t_params[0][data->p_p] = val;
	data->p_p += 1;
	return (EXIT_SUCCESS);
}

static int	ft_registre(t_var *data, t_process *proc, int *n)
{
	unsigned int	r_num;

	data->t_params[1][data->p_p] =
		data->vm[(proc->pc + *n) % MEM_SIZE];
	r_num = data->t_params[1][data->p_p];
	if (r_num < 1 || r_num > REG_NUMBER)
		return (EXIT_FAILURE);
	data->t_params[0][data->p_p] = (unsigned int)proc->registre[r_num].val;
	data->p_p += 1;
	*n += 1;
	return (EXIT_SUCCESS);
}

static int	ft_split_params(t_var *data, t_process *proc, int dir_oct, int idx)
{
	int		i;
	int		err;
	int 	n;

	i = 8;
	data->p_p = 0;
	n = 2;
	while ((i -= 2))
	{
		err = 0;
		if (!(unsigned char)(0x3 & (data->vm[(proc->pc + 1) % MEM_SIZE] >> i)))
			break ;
		else if ((unsigned char)(0x3 &
			(data->vm[(proc->pc + 1) % MEM_SIZE] >> i)) == REG_CODE)
			err = ft_registre(data, proc, &n);
		else if ((unsigned char)(0x3 &
			(data->vm[(proc->pc + 1) % MEM_SIZE] >> i)) == DIR_CODE)
			err = ft_direct(data, proc, dir_oct, &n);
		else if ((unsigned char)(0x3 &
			(data->vm[(proc->pc + 1) % MEM_SIZE] >> i)) == IND_CODE)
			err = ft_indirect(data, proc, idx, &n);
		if (err != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			ft_params_opcode(t_var *data, t_process *proc, int dir_oct,
				int idx)
{
	if (proc->mem_op_code == 0x0c || proc->mem_op_code == 0x0f
		|| proc->mem_op_code == 0x09)
	{
		data->t_params[0][0] =
			((data->vm[(proc->pc + 1) % MEM_SIZE] << 8)
			+ data->vm[(proc->pc + 2) % MEM_SIZE]);
		//ft_printf("data_tparam = %hd\n", data->t_params[0][0]);
	}
	else if (proc->mem_op_code == 0x01)
	{
		data->t_params[0][0] =
			((data->vm[(proc->pc + 1) % MEM_SIZE] << (OCT * 3))
			+ (data->vm[(proc->pc + 2) % MEM_SIZE] << (OCT * 2))
			+ (data->vm[(proc->pc + 3) % MEM_SIZE] << OCT)
			+ data->vm[(proc->pc + 4) % MEM_SIZE]);
	}
	else
	{
		if (ft_split_params(data, proc, dir_oct, idx))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
