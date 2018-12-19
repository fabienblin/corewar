/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   secure_h.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 23:36:12 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:36:18 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "decompiler.h"

int	ft_secure_h(void)
{
	if (IND_SIZE != 2 || REG_SIZE != 4 || DIR_SIZE != REG_SIZE || REG_CODE != 1
		|| DIR_CODE != 2 || IND_CODE != 3 || T_REG != 1 || T_DIR != 2
		|| T_IND != 4 || T_LAB != 8)
	{
		ft_printf("Error value in .h\n");
		exit(-1);
	}
	return (0);
}
