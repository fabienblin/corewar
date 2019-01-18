/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 14:03:57 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 18:17:33 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_check_champ(t_var *data, char **av, long len, int n)
{
	static long		player_nbr = 0;
	static int		i = 0;
	long			check_nbr;

	data->pos_player = data->nb_champion - ++i;
	ft_control_player(data, player_nbr);
	if (len == 2)
	{
		if (!ft_strisdigit_pos_neg(av[n - 1]) || ft_limits(av[n - 1],
				SIGNED, INT_MAX))
			exit(my_exit(&data->lst_free, __FILE__,
				(char *)__func__, __LINE__));
		check_nbr = ft_atoi(av[n - 1]);
		len = ft_strlen(av[n]);
		check_nbr >= player_nbr ? (player_nbr = check_nbr) :
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	}
	if (((av[n][len - 1]) + (av[n][len - 2] << 8) + (av[n][len - 3]
			<< 16) + (av[n][len - 4] << 24) & 0xFFFFFFFF) == DOT_COR)
		ft_read_dot_cor(data, av[n], player_nbr, data->pos_player);
	else
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	player_nbr++;
}

static void		ft_check_verbose(t_var *data, char **av, int n)
{
	if (data->v > 0)
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	data->v = ft_atoi(av[n]);
	if (data->v == 2 || data->v == 4 || data->v == 6 || data->v == 8)
		n += 1;
	else
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
}

static void		ft_check_dump(int n, char **av, int *dump, t_var *data)
{
	long	res;

	res = ft_atoi(av[n]);
	if (*dump > 0)
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	if (av[n][0] == '-' || res == 0)
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	if (!ft_strisdigit_pos_neg(av[n]) || ft_limits(av[n], SIGNED, INT_MAX))
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	*dump += 1;
	data->dump_value = (unsigned)res;
}

void			ft_check_arg(int ac, char **av, t_var *d)
{
	int		n;
	long	len;
	int		dump;

	n = 0;
	dump = 0;
	while (++n < ac)
	{
		d->n = 0;
		if (!ft_strcmp(av[n], "-dump") && av[n + 1])
			ft_check_dump(++n, av, &dump, d);
		else if (!ft_strcmp(av[n], "-v") && av[n + 1])
			ft_check_verbose(d, av, ++n);
		else if ((len = ft_strlen(av[n])) > 4)
			ft_check_champ(d, av, len, n);
		else if (!ft_strcmp(av[n], "-n") && av[n + 2])
		{
			d->n = 1;
			d->a_n = 1;
			ft_strisdigit_pos_neg(av[++n]) ? ft_check_champ(d, av, len, ++n)
			: exit(my_exit(&d->lst_free, __FILE__, (char *)__func__, __LINE__));
		}
		else
			exit(my_exit(&d->lst_free, __FILE__, (char *)__func__, __LINE__));
	}
}
