/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:01:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 15:56:37 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

t_env g_env;

void	init_env(void)
{
	g_env.grid = ft_newgrid(1,1);
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
		ft_printf("test %d\n", run);
		//sleep(1);
		run++;
	}
	ft_exit_corewar(NULL);
	return (0);
}