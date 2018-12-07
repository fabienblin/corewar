/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:01:55 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 15:41:44 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int main(int argc, char **argv)
{
	int	fd;
	(void)argc;
	(void)argv;

	if (argc != 2)
		ft_exit_asm(USAGE);
	//init();
	fd = open(argv[1], O_RDONLY);
	// verif lexicale du fichier
	lexer(fd);
	ft_printf("----- Demarrage du generator -----\n");
	ft_generator(fd, argv);
	// création de l'AST (Abstract Syntax Tree)
	//parse(fd);
	// .cor
	//generate();
	close(fd);
	ft_exit_asm(NULL);
	return (0);
}
