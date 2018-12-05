/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   label.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 17:19:37 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 17:31:41 by fablin      ###    #+. /#+    ###.fr     */
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
		new_label->name = name;
	if (is_declared)
		new_label->is_declared = is_declared;
	if (is_used)
		new_label->is_used = is_used;
	return (new_label);
}

void	del_label(t_label **label)
{
	ft_memdel((void **)label);
}