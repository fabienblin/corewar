/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:01:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 12:38:33 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

t_env g_env;

void	init_env(void)
{
	g_env.grid = ft_newgrid(64,64);
}

#include <unistd.h>

int main(int argc, char **argv)
{
	int run;
	(void)argc;
	(void)argv;
	init_env();
	run = 1;
	while (run)
	{
		ft_printf("test %1000d\n", run);
		run++;
	}
	ft_exit_corewar(NULL);
	return (0);
}