/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:16:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:02:16 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

// init de l'env global
void init(void)
{
	g_env.op_tab = get_op_tab();
	g_env.ast = NULL; // potentiellement un t_ntree (voir libft)
	g_env.name = NULL; // ligne 1
	g_env.comment = NULL; // ligne 2
}
