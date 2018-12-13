/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:01:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 19:09:20 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	(void)argv;
	if (argc != 2)
		ft_exit_asm(USAGE);
	fd = open(argv[1], O_RDONLY);
	lexer(fd);
	ft_printf("----- Demarrage du generator -----\n");
	ft_generator(fd, argv);
	close(fd);
	ft_exit_asm(NULL);
	return (0);
}
