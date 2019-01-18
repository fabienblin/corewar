/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_champion.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 18:16:59 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 18:17:42 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_first_proc(t_var *data, unsigned int nbr)
{
	t_process				*new_process;
	t_process				*sav_start;

	sav_start = data->lst_process;
	if (!(new_process = my_memalloc(&data->lst_free, sizeof(t_process))))
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	new_process->next = NULL;
	new_process->id = ++data->id_proc;
	new_process->pc = ((MEM_SIZE / (data->nb_champion)) *
						(data->nb_champion - data->pos_player - 1));
	new_process->registre[1].val = ~nbr;
	new_process->flag = 0;
	new_process->end_op = 0;
	if (!data->lst_process)
		data->lst_process = new_process;
	else
	{
		new_process->next = sav_start;
		data->lst_process = new_process;
	}
}

int				create_champion(t_var *data, unsigned int nbr,
					unsigned char *cor, unsigned int size)
{
	data->tab_champion[data->pos_player].size = size;
	data->tab_champion[data->pos_player].nbr = ~nbr;
	data->tab_champion[data->pos_player].n = data->n;
	if (data->a_n)
		data->tab_champion[data->pos_player].a_n = 1;
	ft_first_proc(data, nbr);
	ft_memcpy(&data->vm[data->lst_process->pc],
		cor, data->tab_champion[data->pos_player].header.prog_size);
	return (EXIT_SUCCESS);
}
