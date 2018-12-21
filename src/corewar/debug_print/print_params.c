/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_params.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 11:10:58 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 11:10:58 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void		print_t_params(t_var *data)
{
	int n = 0;
	int i;
	ft_printf("| %s |\n", __func__);
	while (n < 2)
	{
		i = 0;
		while (i < 3)
		{
			if (n == 0)
				ft_printf("|  Valeur   =\t%15i\t|", data->t_params[n][i]);
			if (n == 1)
				ft_printf("|  Registre =\t%15i\t|", data->t_params[n][i]);
			i++;
		}
		ft_printf("\n");
		n++;
	}
}
