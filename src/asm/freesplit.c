/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   freesplit.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 16:33:31 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 20:22:42 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void freesplit(char ***split)
{
	char	**tmp;
	
	tmp = *split;
	if (!split || !tmp)
		return ;
	while(*tmp)
	{
		ft_strdel(tmp);
		tmp++;
	}
	free(*tmp);
	free(*split);
	*split = NULL;
}