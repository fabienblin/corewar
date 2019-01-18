/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:35:34 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *mem, size_t size)
{
	void	*new;

	new = NULL;
	if (!(new = (void *)malloc(sizeof(size_t) * (size + 1))))
		return (NULL);
	if (mem)
	{
		ft_memcpy(new, mem, size);
		free(mem);
		mem = NULL;
	}
	return (new);
}
