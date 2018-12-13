/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   label.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 17:19:37 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 16:08:25 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_label	*new_label(char *name, int is_declared, int is_used)
{
	t_label	*new_label;

	if (!(new_label = (t_label *)ft_memalloc(sizeof(t_label))))
		return (NULL);
	if (name)
		new_label->name = ft_strdup(name);
	if (is_declared)
		new_label->is_declared = is_declared;
	if (is_used)
		new_label->is_used = is_used;
	return (new_label);
}

void	del_label(void *label, size_t size)
{
	(void)size;
	ft_strdel(&((t_label *)label)->name);
}
