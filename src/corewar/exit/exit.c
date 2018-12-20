/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 15:54:35 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 15:54:35 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int			my_exit(t_free **lst_free, char *file, char *func, int line)
{
	ft_printf("ERROR :\n\tFILE\t : %s\n\tFUNCTION : %s\n\tLINE\t : (%d)\n",
		file, func, line);
	my_auto_free(lst_free);
	return (EXIT_FAILURE);
}
