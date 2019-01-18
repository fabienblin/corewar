/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <slatchma@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 12:46:36 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 14:52:44 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int			ft_conv_bin(int octet_param[8])
{
	int i;
	int p;
	int result;

	i = 7;
	p = 1;
	result = 0;
	while (i >= 0)
	{
		result = result + octet_param[i] * p;
		p = p * 2;
		i--;
	}
	return (result);
}

static void	ft_init_octet_param(int octet_param[8])
{
	int j;

	j = 0;
	while (j < 8)
	{
		octet_param[j] = 0;
		j++;
	}
}

static void	ft_write_octet_param(int octet_param[8], int k, int i, int j)
{
	octet_param[k] = i;
	octet_param[k + 1] = j;
}

int			ft_octet_param(char **tabtext, int i, int nb_arg)
{
	int k;
	int l;
	int octet_param[8];

	k = 0;
	l = i + nb_arg;
	ft_init_octet_param(octet_param);
	while (i < l)
	{
		if (tabtext[i][0] == REGISTER_CHAR)
			ft_write_octet_param(octet_param, k, 0, 1);
		else if (tabtext[i][0] == DIRECT_CHAR)
			ft_write_octet_param(octet_param, k, 1, 0);
		else
			ft_write_octet_param(octet_param, k, 1, 1);
		k = k + 2;
		i++;
	}
	return (ft_conv_bin(octet_param));
}

void		ft_delete_comment(char *line)
{
	int i;

	i = 0;
	if ((i = ft_strsupchr(line, COMMENT_CHAR)) != -1)
	{
		while (line[i] != '\0')
		{
			line[i] = ' ';
			i++;
		}
	}
}
