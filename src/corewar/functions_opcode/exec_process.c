/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_process.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 19:19:49 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:45:10 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_is_op_code(t_var *data, t_process *p_process)
{
	int 	flag;

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

static void		ft_nbr_live_op_code(t_var *data, t_process *p_process, int i)
{
	{
		//ft_printf("        Player(%i) EXECUTE  ==>  PC = 0x%0.2x  ||  index = %i  ||  flag = %i  || end_op = %i  || cycle = %i\n", i, data->vm[p_process->pc], p_process->pc, p_process->flag, p_process->end_op, data->cycle);
		p_process->flag = 0;
		data->op_size = 0;
		ft_bzero(data->t_params, sizeof(data->t_params));
		ft_printf("SANGLIER = %d\n", data->tab_champion[i].nbr);
		tab_opcode(data, p_process, i);
	}
}

static void		ft_no_flag_p_process(t_var *data, t_process *p_process, int i)
{
	//ft_printf("        Player(%i) IN       ==>  PC = 0x%0.2x  ||  index = %i  ||  flag = %i  || end_op = %i  || cycle = %i\n",i, data->vm[p_process->pc], p_process->pc, p_process->flag, p_process->end_op, data->cycle);

	if (!ft_is_op_code(data, p_process))
	{
		p_process->flag = 1;
		p_process->end_op = data->cycle + (data->op_tab[data->vm[p_process->pc]]) - 1;
	}
	else
		p_process->pc++;
}

int				exec_program(t_var *data)
{
	int			i;
	t_process	*p_process;

	i = 0;
	while (i < data->nb_champion)
	{
		p_process = data->tab_champion[i].lst_process;
		while (p_process)
		{
			//ft_printf("pc = 0x%.2x\n",data->vm[p_process->pc]);
			//ft_printf("INIT  PC[%i]  = %i\n",p_process->id, p_process->pc);
			if (!p_process->flag)
				ft_no_flag_p_process(data, p_process, i);
			else if (p_process->end_op == data->cycle)
				ft_nbr_live_op_code(data, p_process, i);
			//ft_printf("flag = %i  || end_op = %i  || cycle = %i\n", p_process->flag, p_process->end_op, data->cycle);
			p_process = p_process->next;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
