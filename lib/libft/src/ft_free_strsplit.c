/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_strsplit.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 13:15:15 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:15:44 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strsplit(char ***split)
{
	char	**tmp;

	tmp = *split;
	if (!split || !tmp)
		return ;
	while (*tmp)
	{
		ft_strdel(tmp);
		tmp++;
	}
	free(*tmp);
	free(*split);
	*split = NULL;
}
