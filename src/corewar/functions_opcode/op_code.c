/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op_code.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 11:53:25 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:45:16 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		tab_opcode_2(t_var *data, t_process *p_process, int i)
{
	if (data->vm[p_process->pc] == 0x0f)
		opcode_lfork(data, p_process, i);
	else if (data->vm[p_process->pc] == 0x01)
		opcode_live(data, p_process);
	else if (data->vm[p_process->pc] == 0x07)
		opcode_or(data, p_process);
	else if (data->vm[p_process->pc] == 0x03)
		opcode_st(data, p_process);
	else if (data->vm[p_process->pc] == 0x0b)
		opcode_sti(data, p_process);
	else if (data->vm[p_process->pc] == 0x05)
		opcode_sub(data, p_process);
	else if (data->vm[p_process->pc] == 0x08)
		opcode_xor(data, p_process);
	else if (data->vm[p_process->pc] == 0x09)
		opcode_zjmp(data, p_process);
	return (EXIT_SUCCESS);
}

int				tab_opcode(t_var *data, t_process *p_process, int i)
{
	if (data->vm[p_process->pc] == 0x04)
		opcode_add(data, p_process);
	else if (data->vm[p_process->pc] == 0x10)
		opcode_aff(data, p_process);
	else if (data->vm[p_process->pc] == 0x06)
		opcode_and(data, p_process);
	else if (data->vm[p_process->pc] == 0x0c)
		opcode_fork(data, p_process, i);
	else if (data->vm[p_process->pc] == 0x02)
		opcode_ld(data, p_process);
	else if (data->vm[p_process->pc] == 0x0a)
		opcode_ldi(data, p_process);
	else if (data->vm[p_process->pc] == 0x0d)
		opcode_lld(data, p_process);
	else if (data->vm[p_process->pc] == 0x0e)
		opcode_lldi(data, p_process);
	else
		tab_opcode_2(data, p_process, i);
	return (EXIT_SUCCESS);
}



