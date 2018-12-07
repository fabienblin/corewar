/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_octet.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 12:48:10 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 12:49:56 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	ft_octet_one(int fdout, int nbre, int *compt)
{
	t_champbits	octet;
	char		tmp;

	octet = *(t_champbits*)&nbre;
	tmp = octet.b4;
	write(fdout, &tmp, sizeof(tmp));
	*compt = *compt + 1;
}

void	ft_octet_two(int fdout, int nbre, int *compt)
{
	t_champbits	octet;
	char		tmp;

	octet = *(t_champbits*)&nbre;
	tmp = octet.b3;
	write(fdout, &tmp, sizeof(tmp));
	tmp = octet.b4;
	write(fdout, &tmp, sizeof(tmp));
	*compt = *compt + 2;
}

void	ft_octet_four(int fdout, int nbre, int *compt)
{
	t_champbits	octet;
	char		tmp;

	octet = *(t_champbits*)&nbre;
	tmp = octet.b1;
	write(fdout, &tmp, sizeof(tmp));
	tmp = octet.b2;
	write(fdout, &tmp, sizeof(tmp));
	tmp = octet.b3;
	write(fdout, &tmp, sizeof(tmp));
	tmp = octet.b4;
	write(fdout, &tmp, sizeof(tmp));
	*compt = *compt + 4;
}

int		ft_comment_header(char *line)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	p = ft_strstr(line, COMMENT_CMD_STRING);
	while (&line[i] != p)
	{
		if (line[i] == COMMENT_CHAR)
			return (1);
		i++;
	}
	return (0);
}
