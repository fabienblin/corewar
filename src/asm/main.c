/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:01:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:35:35 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	secure_file(char *file)
{
	int len;

	len = ft_strlen(file);
	if (len < 2 || file[len - 1] != 's' || file[len - 2] != '.')
	{
		ft_printf("Not file.s\n");
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	(void)argv;
	ft_secure_h();
	if (argc != 2)
		ft_exit_asm(USAGE);
	secure_file(argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) < 0 || errno)
	{
		ft_exit_asm(strerror(errno));
		close(fd);
	}
	lexer(fd);
	ft_generator(fd, argv);
	close(fd);
	ft_exit_asm(NULL);
	return (0);
}
