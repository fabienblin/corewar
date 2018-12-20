/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 22:16:15 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 22:16:46 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "decompiler.h"

static int	ft_init_compt(char param)
{
	if (param == 'R')
		return (1);
	if (param == 'I')
		return (2);
	if (param == 'D')
		return (4);
	if (param == 'd')
		return (2);
	return (0);
}

static int	ft_param_two(t_analyze *myoctet, int *param, int nbre,
			int param_nbre)
{
	*param = *param << 8;
	*param = *param + nbre;
	myoctet->compt--;
	if (param_nbre == 1 && myoctet->compt == 0)
		myoctet->state = myoctet->state - 4;
	if (param_nbre == 2 && myoctet->compt == 0)
		myoctet->state = myoctet->state - 2;
	if (param_nbre == 3 && myoctet->compt == 0)
		myoctet->state = myoctet->state - 1;
	if (myoctet->state == 0)
		return (2);
	else
		return (1);
}

int			ft_param(t_analyze *myoctet, int nbre, char param_type,
			int param_nbre)
{
	if (myoctet->compt == 0)
		myoctet->compt = ft_init_compt(param_type);
	if (param_nbre == 1)
		return (ft_param_two(myoctet, &myoctet->param1_nbre, nbre, param_nbre));
	if (param_nbre == 2)
		return (ft_param_two(myoctet, &myoctet->param2_nbre, nbre, param_nbre));
	if (param_nbre == 3)
		return (ft_param_two(myoctet, &myoctet->param3_nbre, nbre, param_nbre));
	return (-1);
}

static char	ft_bit_octetparam(int b, int opcode)
{
	char	result;
	int		i;
	t_op	*op;

	result = 0;
	i = 0;
	op = get_op_tab();
	if (b == 1)
		return ('R');
	if (b == 3)
		return ('I');
	if (b == 2)
	{
		while (i < 16 && op[i].bin != opcode)
		{
			i++;
		}
		if (op[i].dir_size == 1)
			return ('d');
		else
			return ('D');
	}
	return (0);
}

int			ft_analyze_octet_param(t_analyze *myoctet, int nbre)
{
	t_bitoctetparam octet;

	myoctet->state = myoctet->state - 8;
	octet = *(t_bitoctetparam*)&nbre;
	if (nbre == 0)
	{
		myoctet->state = 0;
		return (-1);
	}
	myoctet->param1_type = ft_bit_octetparam(octet.b1, myoctet->opcode);
	myoctet->param2_type = ft_bit_octetparam(octet.b2, myoctet->opcode);
	myoctet->param3_type = ft_bit_octetparam(octet.b3, myoctet->opcode);
	return (1);
}
