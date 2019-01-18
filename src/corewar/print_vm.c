/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_vm.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/17 13:45:28 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 13:07:50 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				print_dump(t_var *data)
{
	int				i;
	int				j;
	unsigned char	*tmp;

	i = 0;
	tmp = data->vm;
	while (i < MEM_SIZE)
	{
		j = 0;
		ft_printf("0x%0.4x : ", i);
		while (j < 64)
		{
			ft_printf("%0.2x ", *tmp);
			tmp++;
			i++;
			j++;
		}
		ft_printf("\n");
	}
	return (EXIT_SUCCESS);
}
