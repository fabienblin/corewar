/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cycle_nb_live.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 11:21:44 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:46:58 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				t_process_create(t_var *data, t_process *p_process, int i,
					int idx)
{
	t_process		*sav_start;
	t_process		*new_process;

	sav_start = data->tab_champion[i].lst_process;
	if (!(new_process = my_memalloc(&data->lst_free, sizeof(t_process))))
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	ft_memcpy(new_process, p_process, sizeof(t_process));
	if (idx)
		new_process->pc = p_process->pc
			+ ((short)data->t_params[0][0] % IDX_MOD);
	else
		new_process->pc = p_process->pc + ((short)data->t_params[0][0]);
	if ((short)new_process->pc < 0)
		new_process->pc = MEM_SIZE - new_process->pc;
	new_process->id = ++data->id_proc;
	new_process->end_op = 0;
	new_process->next = sav_start;
	new_process->flag = 0;
	data->tab_champion[i].lst_process = new_process;
	return (EXIT_SUCCESS);
}

static int		t_process_del(t_var *data, t_process *p_process, int i)
{
	t_process	*save_next;
	t_process	*tmp_process;
	t_process	*prev;

	save_next = p_process->next;
	if (p_process == data->tab_champion[i].lst_process)
	{
		my_free(&data->lst_free, (size_t)p_process);
		data->tab_champion[i].lst_process = save_next;
	}
	else
	{
		tmp_process = data->tab_champion[i].lst_process;
		prev = NULL;
		while (tmp_process && tmp_process != p_process)
		{
			prev = tmp_process;
			tmp_process = tmp_process->next;
		}
		my_free(&data->lst_free, (size_t)p_process);
		prev->next = save_next;
	}
	return (EXIT_SUCCESS);
}

static int		update_cycle_process(t_var *data)
{
	size_t		i;
	t_process	*p_process;

	i = 0;
	while (i < data->nb_champion)
	{
		p_process = data->tab_champion[i].lst_process;
		while (p_process)
		{
			p_process->nbr_live = 0;
			p_process = p_process->next;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int		action_cycle_process(t_var *data)
{
	if (data->nb_live >= NBR_LIVE || !data->check_max_check)
	{
	//	ft_printf("CYCLE_TO_DIE\t[OK]\t: %u\n", data->check_cycle_delta);
		data->check_cycle_delta -= CYCLE_DELTA;
		data->check_cycle += data->check_cycle_delta;
		data->check_max_check = MAX_CHECKS - 1;
		if (data->v == 6)
			ft_printf("Cycle to die is now %i\n", data->check_cycle_delta);
	}
	else
	{
		data->check_max_check--;
		data->check_cycle += data->check_cycle_delta;
	}
	data->nb_live = 0;
	return (EXIT_SUCCESS);
}

int				cycle_to_die(t_var *data)
{
	int			i;
	t_process	*p_process;

	i = 0;
	while (i < data->nb_champion)
	{
		//ft_printf("verif  champ : %i  || live = %i\n", i, data->tab_champion[i].nb_live);
		p_process = data->tab_champion[i].lst_process;
		while (p_process)
		{
			//ft_printf("P_%i\n", p_process->id);
			if (!p_process->nbr_live)
				t_process_del(data, p_process, i);
			p_process = p_process->next;
		}
		data->nb_live += data->tab_champion[i].nb_live;
		data->tab_champion[i].nb_live = 0;
		i++;
	}
	action_cycle_process(data);
	update_cycle_process(data);
	return (EXIT_SUCCESS);
}
