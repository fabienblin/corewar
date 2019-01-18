/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 14:08:16 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 18:06:05 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_print_intro_vm(t_var *data)
{
	unsigned int	i;
	long			n;

	i = 1;
	ft_printf("Introducing contestants...\n");
	while (i <= data->nb_champion)
	{
		if (!data->tab_champion[data->nb_champion - i].n
			&& !data->tab_champion[data->nb_champion - i].a_n)
			n = ~data->tab_champion[data->nb_champion - i].nbr + 1;
		else
			n = ~data->tab_champion[data->nb_champion - i].nbr;
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			n,
			data->tab_champion[data->nb_champion - i].size,
			data->tab_champion[data->nb_champion - i].header.prog_name,
			data->tab_champion[data->nb_champion - i].header.comment);
		i++;
	}
}

static void		ft_init_data_corewar_2(t_var *data)
{
	data->op_tab[1] = 10;
	data->op_tab[2] = 5;
	data->op_tab[3] = 5;
	data->op_tab[4] = 10;
	data->op_tab[5] = 10;
	data->op_tab[6] = 6;
	data->op_tab[7] = 6;
	data->op_tab[8] = 6;
	data->op_tab[9] = 20;
	data->op_tab[10] = 25;
	data->op_tab[11] = 25;
	data->op_tab[12] = 800;
	data->op_tab[13] = 10;
	data->op_tab[14] = 50;
	data->op_tab[15] = 1000;
	data->op_tab[16] = 2;
}

static void		ft_init_data_corewar(t_var *data)
{
	data->vm = NULL;
	data->cycle = 1;
	data->check_cycle = 0;
	data->check_cycle_delta = 0;
	data->check_max_check = 0;
	data->nb_live = 0;
	data->nb_champion = 0;
	data->stop_corewar = 0;
	data->dump_value = 0;
	data->pos_player = 0;
	data->lst_free = NULL;
	data->p_p = 0;
	data->v = 0;
	data->id_proc = 0;
	data->a_n = 0;
	ft_bzero(data->tab_champion, sizeof(t_champion) * MAX_PLAYERS);
	ft_init_data_corewar_2(data);
}

static void		ft_print_usage(void)
{
	ft_printf("Usage : ./corewar [-dump nbr_cycles -n number <champion1.cor>");
	ft_printf("-n number <champion2.cor>... -v]\n");
	ft_printf("\t-dump N\t: Dumps memory after N cycles then exits\n");
	ft_printf("\t-n N\t: Champion number\n");
	ft_printf(
		"\t-v N\t: Verbosity levels, can be added together to enable several"
		"\n");
	ft_printf("\t\t- 2\t: Show cycles\n");
	ft_printf("\t\t- 4\t: Show operations (Params are NOT litteral ...)\n");
	exit(EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	t_var	data;

	if (ac == 1)
		ft_print_usage();
	ft_init_data_corewar(&data);
	ft_count_nbr_champs(ac, av, &data);
	create_vm(&data, &data.vm, MEM_SIZE);
	ft_check_arg(ac, av, &data);
	ft_print_intro_vm(&data);
	cycle_management(&data, data.dump_value);
	my_auto_free(&data.lst_free);
	return (EXIT_SUCCESS);
}
