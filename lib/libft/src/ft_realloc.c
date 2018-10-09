/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 14:48:43 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 18:46:43 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **mem, size_t size)
{
	void	*realloc;

	realloc = NULL;
	if (!(realloc = (void *)malloc(size * sizeof(**mem))))
		return (NULL);
	if (*mem)
	{
		ft_memcpy(realloc, *mem, size);
		free(*mem);
		*mem = realloc;
	}
	return (realloc);
}
