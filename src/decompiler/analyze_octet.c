/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   analyze_octet.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 22:15:18 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 22:15:45 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "decompiler.h"

static int	ft_init_myoctet(t_analyze *myoctet)
{
	myoctet->compt = 0;
	myoctet->param1_type = 0;
	myoctet->param2_type = 0;
	myoctet->param3_type = 0;
	myoctet->opcode = 0;
	myoctet->octet_param = 0;
	myoctet->state = 0;
	myoctet->param1_nbre = 0;
	myoctet->param2_nbre = 0;
	myoctet->param3_nbre = 0;
	return (0);
}

static void	ft_analyze_opcode_two(t_analyze *myoctet, int dir_size)
{
	if (dir_size == 1)
		myoctet->param1_type = 'd';
	else
		myoctet->param1_type = 'D';
	myoctet->state = myoctet->state + 4;
}

static int	ft_analyze_opcode(t_analyze *myoctet, int nbre)
{
	int		i;
	t_op	*op;

	op = get_op_tab();
	i = 0;
	while (i < 16 && op[i].bin != nbre)
	{
		i++;
	}
	myoctet->opcode = nbre;
	if (op[i].octet_param == 1)
	{
		myoctet->state = myoctet->state + 8;
		if (op[i].nb_arg == 1)
			myoctet->state = myoctet->state + 4;
		if (op[i].nb_arg == 2)
			myoctet->state = myoctet->state + 6;
		if (op[i].nb_arg == 3)
			myoctet->state = myoctet->state + 7;
	}
	else
		ft_analyze_opcode_two(myoctet, op[i].dir_size);
	return (1);
}

int			ft_analyze_octet(int init, t_analyze *myoctet, int nbre)
{
	if (init == 1)
		return (ft_init_myoctet(myoctet));
	if (myoctet->state == 0)
		ft_init_myoctet(myoctet);
	if (myoctet->state == 0 && 0 < nbre && nbre <= 16)
		return (ft_analyze_opcode(myoctet, nbre));
	if ((myoctet->state & 8) == 8)
		return (ft_analyze_octet_param(myoctet, nbre));
	if ((myoctet->state & 4) == 4)
		return (ft_param(myoctet, nbre, myoctet->param1_type, 1));
	if ((myoctet->state & 2) == 2)
		return (ft_param(myoctet, nbre, myoctet->param2_type, 2));
	if ((myoctet->state & 1) == 1)
		return (ft_param(myoctet, nbre, myoctet->param3_type, 3));
	return (0);
}
