/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_live.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:01:10 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 10:01:10 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				opcode_live(t_var *data, t_process *p_process)
{
	size_t	i;

	if (!ft_params_opcode(data, p_process, 4, 0))
	{
		if (data->v == 4 || data->v == 6)
			ft_printf("P %4i | live %i\n", p_process->id,
				data->t_params[0][0]);
		i = 0;
		//ft_printf("LIIIIIIIIIIIIIIIIIIIIIIIVE\n");
		while (i < data->nb_champion)
		{
		//	ft_printf("nbr = % i || param = %i\n", data->tab_champion[i].nbr, data->t_params[0][0]);
			if (data->tab_champion[i].nbr == data->t_params[0][0])
			{
				//data->last_live = data->t_params[0][0];
				data->last_live = i;
		//		ft_printf("un processus dit que le joueur %u(%s) est en vie\n", ~data->tab_champion[i].nbr, data->tab_champion[i].header.prog_name);
				break;
			}
			i++;
		}
		data->nb_live++;
		p_process->nbr_live++;
		p_process->pc = ((p_process->pc + 5) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc = ((p_process->pc + 5) % MEM_SIZE);
	return (EXIT_FAILURE);
}