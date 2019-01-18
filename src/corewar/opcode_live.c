/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_live.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:01:10 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 18:36:38 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void		opcode_live_2(t_var *data)
{
	long	i;
	long	n;

	i = -1;
	n = 0;
	while (++i < data->nb_champion)
	{
		if (data->tab_champion[i].nbr == data->t_params[0][0])
		{
			if (!data->tab_champion[i].n && !data->tab_champion[i].a_n)
				n = ~data->tab_champion[i].nbr + 1;
			else
				n = ~data->tab_champion[i].nbr;
			if (data->v == 0)
				ft_printf("un processus dit que le joueur %i(%s) est en vie\n",
					n, data->tab_champion[i].header.prog_name);
			data->last_live = i;
			break ;
		}
	}
}

int				opcode_live(t_var *data, t_process *p_process)
{
	if (!ft_params_opcode(data, p_process, 4, 0))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | live %i\n", p_process->id, data->t_params[0][0]);
		opcode_live_2(data);
		data->nb_live++;
		p_process->nbr_live++;
		p_process->pc = ((p_process->pc + 5) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc = ((p_process->pc + 5) % MEM_SIZE);
	return (EXIT_FAILURE);
}
