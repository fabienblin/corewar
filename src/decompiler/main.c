/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 22:04:20 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 22:04:28 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "decompiler.h"

static int	ft_name_file(char *namein)
{
	int len;

	len = ft_strlen(namein);
	if (len < 4)
		return (0);
	else
	{
		if (namein[len - 1] == 'r' && namein[len - 2] == 'o' &&
			namein[len - 3] == 'c' && namein[len - 4] == '.')
			return (1);
	}
	ft_printf("%s no type .cor\n", namein);
	return (0);
}

static int	ft_size_th(int fd)
{
	int				nbre;
	unsigned char	c;
	int				i;

	nbre = 0;
	i = 0;
	while (i < 4)
	{
		read(fd, &c, 1);
		nbre = (nbre << 8) + c;
		i++;
	}
	return (nbre);
}

static int	ft_size_file(int fd)
{
	int		size_th;
	int		compt;
	char	c;

	size_th = 0;
	compt = 0;
	lseek(fd, (PROG_NAME_LENGTH + 8), SEEK_SET);
	size_th = ft_size_th(fd);
	lseek(fd, (PROG_NAME_LENGTH + 16 + COMMENT_LENGTH), SEEK_SET);
	while (read(fd, &c, 1) == 1)
	{
		compt++;
	}
	if (size_th != compt)
		return (1);
	return (0);
}

static int	ft_test_file(char *namein)
{
	int fd;
	int c;
	int	compt;

	c = 0;
	compt = 0;
	fd = open(namein, O_RDONLY);
	while (read(fd, &c, 1) == 1)
	{
		compt++;
	}
	if (compt < (PROG_NAME_LENGTH + 16 + COMMENT_LENGTH))
	{
		ft_printf("file %s not valid\n", namein);
		close(fd);
		return (0);
	}
	if (ft_size_file(fd) == 1)
	{
		ft_printf("FILE %s not valid\n", namein);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int			main(int argc, char **argv)
{
	int	fdin;

	ft_secure_h();
	if (argc == 2)
	{
		if (ft_name_file(argv[1]) == 1)
		{
			if (ft_test_file(argv[1]) == 1)
			{
				fdin = open(argv[1], O_RDONLY);
				ft_fileout_cor(fdin, argv[1]);
				close(fdin);
			}
		}
	}
	else
		ft_printf("error\n");
	return (0);
}
