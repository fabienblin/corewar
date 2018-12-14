/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:01:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:11:07 by fablin      ###    #+. /#+    ###.fr     */
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
	if ((fd = open(argv[1], O_RDONLY)) < 0 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}
	lexer(fd);
	ft_generator(fd, argv);
	ft_printf("Writing output program to %s.cor\n", argv[1]);
	close(fd);
	ft_exit_asm(NULL);
	return (0);
}
