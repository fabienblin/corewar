/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corewar.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:02:53 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 13:58:43 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "libft.h"
# include "op.h"

typedef struct	s_env
{
	t_grid	*grid;
	t_op op_tab[17];
}				t_env;

void	ft_exit_corewar(char *msg);

#endif