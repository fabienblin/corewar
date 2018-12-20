/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_vm.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 11:21:44 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:47:09 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int				create_vm(t_var *data, unsigned char **virtual_machine,
					size_t size_vm)
{
	if (!(*virtual_machine = my_memalloc(&data->lst_free, size_vm)))
		return (EXIT_FAILURE);
	ft_bzero(*virtual_machine, size_vm);
	return (EXIT_SUCCESS);
}
