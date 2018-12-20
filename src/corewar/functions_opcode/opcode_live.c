/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_live.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:01:10 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:45:57 by fablin      ###    #+. /#+    ###.fr     */
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
		while (i < data->nb_champion)
		{
			if(data->tab_champion[i].nbr == data->t_params[0][0])
			{
				//ft_printf("champ %i : VIVANT\n", i);
				data->tab_champion[i].nb_live++;
				data->last_live = data->t_params[0][0];
				break;
			}
			i++;
		}
		p_process->nbr_live++;
		p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc = ((p_process->pc + 1) % MEM_SIZE);
	return (EXIT_FAILURE);
}