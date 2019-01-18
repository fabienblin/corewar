/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_process.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 19:19:49 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 19:19:49 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_is_op_code(t_var *data, t_process *p_process)
{
	int		flag;

	flag = 0;
	flag = (data->vm[p_process->pc] == 0x0f) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x01) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x07) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x03) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x0b) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x05) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x08) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x09) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x04) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x10) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x06) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x0c) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x02) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x0a) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x0d) ? 1 : flag;
	flag = (data->vm[p_process->pc] == 0x0e) ? 1 : flag;
	if (flag == 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static void		ft_nbr_live_op_code(t_var *data, t_process *p_process)
{
	p_process->flag = 0;
	data->op_size = 1;
	ft_bzero(data->t_params, sizeof(data->t_params));
	tab_opcode(data, p_process);
}

static void		ft_no_flag_p_process(t_var *data, t_process *p_proc)
{
	if (!ft_is_op_code(data, p_proc))
	{
		p_proc->mem_op_code = data->vm[p_proc->pc];
		p_proc->flag = 1;
		p_proc->end_op = data->cycle + (data->op_tab[data->vm[p_proc->pc]]) - 1;
	}
	else
		p_proc->pc = (p_proc->pc + 1) % MEM_SIZE;
}

int				exec_program(t_var *data)
{
	t_process	*p_process;

	p_process = data->lst_process;
	while (p_process)
	{
		if (!p_process->flag)
			ft_no_flag_p_process(data, p_process);
		else if (p_process->end_op == data->cycle)
			ft_nbr_live_op_code(data, p_process);
		p_process = p_process->next;
	}
	return (EXIT_SUCCESS);
}
