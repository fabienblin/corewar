/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fileout_cor.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 22:08:20 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 22:08:44 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "decompiler.h"

static char	*ft_namefileout(char *namein)
{
	int		len;
	char	*nameout;
	int		i;

	i = 0;
	len = ft_strlen(namein) - 4;
	nameout = (char*)malloc(sizeof(char) * (len + 7));
	if (nameout == NULL)
		return (NULL);
	while (i < len)
	{
		nameout[i] = namein[i];
		i++;
	}
	nameout[i] = '_';
	nameout[i + 1] = 'd';
	nameout[i + 2] = 'e';
	nameout[i + 3] = 'c';
	nameout[i + 4] = '.';
	nameout[i + 5] = 's';
	nameout[i + 6] = '\0';
	return (nameout);
}

static void	ft_decompiler_header(int fdin, int fdout)
{
	char c;

	c = 1;
	write(fdout, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING));
	write(fdout, "\t\t\"", 3);
	lseek(fdin, 4, SEEK_SET);
	while (c != 0)
	{
		read(fdin, &c, 1);
		if (c != 0)
			write(fdout, &c, 1);
	}
	write(fdout, "\"\n", 2);
	write(fdout, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING));
	write(fdout, "\t\"", 2);
	lseek(fdin, (PROG_NAME_LENGTH + 12), SEEK_SET);
	c = 1;
	while (c != 0)
	{
		read(fdin, &c, 1);
		if (c != 0)
			write(fdout, &c, 1);
	}
	write(fdout, "\"\n\n", 3);
}

static void	ft_decompiler_body(int fdin, int fdout)
{
	int				result;
	unsigned char	c;
	int				state;
	t_analyze		myoctet;

	result = 0;
	c = 0;
	state = 1;
	lseek(fdin, (PROG_NAME_LENGTH + 16 + COMMENT_LENGTH), SEEK_SET);
	result = ft_analyze_octet(1, &myoctet, 0);
	while (state > 0 && result != -1)
	{
		result = ft_analyze_octet(1, &myoctet, 0);
		write(fdout, "\n", 1);
		while (result != 2 && result != -1 && state > 0)
		{
			state = read(fdin, &c, 1);
			if (state == 1)
				result = ft_analyze_octet(0, &myoctet, c);
		}
		ft_write_dec_body(fdout, myoctet);
	}
}

void		ft_fileout_cor(int fdin, char *filein)
{
	int		fdout;
	char	*nameout;

	nameout = NULL;
	nameout = ft_namefileout(filein);
	fdout = open(nameout, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU
			| S_IRWXG | S_IRWXO);
	ft_decompiler_header(fdin, fdout);
	ft_decompiler_body(fdin, fdout);
	ft_printf("writing decompiler file to %s\n", nameout);
	close(fdout);
	ft_strdel(&nameout);
}
