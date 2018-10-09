/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strgen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 16:28:10 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 19:33:55 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strgen(int c, int len)
{
	char	*gen;

	if (!(gen = ft_strnew(len)))
		return (NULL);
	gen = ft_memset(gen, c, len);
	return (gen);
}
