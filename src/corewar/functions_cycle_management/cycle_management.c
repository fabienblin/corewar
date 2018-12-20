/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cycle_management.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 15:48:05 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:44:57 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		init_cycle_management(t_var *data)
{
	data->check_cycle = CYCLE_TO_DIE;
	data->check_max_check = MAX_CHECKS - 1;
	data->check_cycle_delta = CYCLE_TO_DIE;
	data->stop_corewar = 0;
	data->nb_live = 0;
	return (EXIT_SUCCESS);
}

int				cycle_management(t_var *data, unsigned long nb_dump)
{
	int		end_dump;

	end_dump = 0;
	init_cycle_management(data);
	while (!data->stop_corewar)
	{
		data->cycle++;
		if (data->v == 6)
			ft_printf("It is now cycle %u\n", data->cycle);
		if (data->cycle == data->check_cycle)
			cycle_to_die(data);
		exec_program(data);
		if (nb_dump > 0 && nb_dump == data->cycle)
		{
			end_dump = 1;
			print_dump(data);
			data->stop_corewar = 1;
		}
		stop_corewar(data);
	}
	if (!end_dump)
		ft_printf("Contestant %d, \"%s\", has won !\n",
		~data->tab_champion[data->nb_champion - ~data->last_live - 1].nbr + 1,
		data->tab_champion[data->nb_champion
		- ~data->last_live - 1].header.prog_name);
	return (EXIT_SUCCESS);
}
