/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_destructors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 13:08:40 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 18:58:09 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_format_lst(t_format *f)
{
	if (f)
	{
		if (f->next)
			ft_del_format_lst(f->next);
		free(f->tostring);
		free(f->arg);
		free(f->form);
		free(f);
	}
}
