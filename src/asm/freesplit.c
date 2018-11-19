/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   freesplit.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 16:33:31 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 16:39:12 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void freesplit(char ***split)
{
	char	**tmp;
	
	tmp = *split;
	if (!tmp)
		return ;
	while(*tmp)
	{
		ft_strdel(tmp);
		tmp++;
	}
	*split = NULL;
}