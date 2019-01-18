/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cycle_nb_lives.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 11:21:44 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 22:02:50 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void			t_process_dell_2(t_process *p_process,
		t_process **tmp_process, t_process **prev)
{
	*prev = NULL;
	while (*tmp_process && *tmp_process != p_process)
	{
		*prev = *tmp_process;
		*tmp_process = (*tmp_process)->next;
	}
}

static t_process	*t_process_del(t_var *data, t_process *p_process)
{
	t_process	*save_next;
	t_process	*tmp_process;
	t_process	*prev;

	save_next = p_process->next;
	prev = NULL;
	if (p_process == data->lst_process)
	{
		my_free(&data->lst_free, (size_t)p_process);
		data->lst_process = save_next;
	}
	else
	{
		tmp_process = data->lst_process;
		t_process_dell_2(p_process, &tmp_process, &prev);
		my_free(&data->lst_free, (size_t)p_process);
		p_process = NULL;
		if (prev == NULL)
			prev = data->lst_process;
		prev->next = save_next;
	}
	return (prev);
}

static int			update_cycle_process(t_var *data)
{
	t_process	*p_process;

	p_process = data->lst_process;
	while (p_process)
	{
		p_process->nbr_live = 0;
		p_process = p_process->next;
	}
	return (EXIT_SUCCESS);
}

static int			action_cycle_process(t_var *data)
{
	if (data->nb_live >= NBR_LIVE || !data->check_max_check)
	{
		data->check_cycle_delta -= CYCLE_DELTA;
		data->check_cycle += data->check_cycle_delta;
		data->check_max_check = MAX_CHECKS - 1;
		if (data->v == 2 || data->v == 6)
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

int					cycle_to_die(t_var *data)
{
	t_process	*next;
	t_process	*p_process;

	p_process = data->lst_process;
	while (p_process)
	{
		next = NULL;
		if (p_process && p_process->nbr_live <= 0)
		{
			next = p_process->next;
			p_process = t_process_del(data, p_process);
		}
		if (p_process)
			p_process = p_process->next;
		else
			p_process = next;
	}
	action_cycle_process(data);
	update_cycle_process(data);
	return (EXIT_SUCCESS);
}
