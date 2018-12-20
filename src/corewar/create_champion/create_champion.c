/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_champion.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 18:16:59 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:44:41 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int			create_champion(t_var *data, unsigned int nbr, unsigned char *cor,
				unsigned int size)
{
	if (!(data->tab_champion[data->pos_player ].lst_process =
			my_memalloc(&data->lst_free, sizeof(t_process))))
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	//ft_printf("pos_player = %i\n", data->pos_player);
	data->tab_champion[data->pos_player].size = size;
	data->tab_champion[data->pos_player].nb_live = 0;
	data->tab_champion[data->pos_player].nbr = ~nbr;
	data->tab_champion[data->pos_player].lst_process->registre[1].val = ~nbr;
	//ft_printf("registre[1].val = %.8x\n", data->tab_champion[data->pos_player].lst_process->registre[1].val);
	data->tab_champion[data->pos_player].lst_process->pc = ((MEM_SIZE / (data->nb_champion)) * (data->nb_champion - data->pos_player - 1));
	ft_memcpy(&data->vm[data->tab_champion[data->pos_player].lst_process->pc],
			cor, data->tab_champion[data->pos_player].header.prog_size);
	data->tab_champion[data->pos_player].lst_process->id = ++data->id_proc;
	return (EXIT_SUCCESS);
}
