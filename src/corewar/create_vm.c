/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_vm.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 11:21:44 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 14:09:07 by fpupier     ###    #+. /#+    ###.fr     */
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

int				t_process_create(t_var *data, t_process *p_proc, int idx)
{
	t_process		*sav_start;
	t_process		*new_process;

	sav_start = data->lst_process;
	if (!(new_process = my_memalloc(&data->lst_free, sizeof(t_process))))
		exit(my_exit(&data->lst_free, __FILE__, (char *)__func__, __LINE__));
	ft_memcpy(new_process, p_proc, sizeof(t_process));
	if (idx)
		new_process->pc = p_proc->pc + ((short)data->t_params[0][0] % IDX_MOD);
	else
		new_process->pc = (p_proc->pc + (short)data->t_params[0][0]) % MEM_SIZE;
	if ((short)new_process->pc < 0)
		new_process->pc = (MEM_SIZE + new_process->pc) % MEM_SIZE;
	new_process->id = ++data->id_proc;
	new_process->end_op = 0;
	new_process->flag = 0;
	new_process->next = sav_start;
	data->lst_process = new_process;
	return (EXIT_SUCCESS);
}
