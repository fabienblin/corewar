/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_param.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 12:50:09 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 12:50:58 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_labelg	*ft_write_label(t_labelg *lstlabel, char *text, t_ggeneral *report)
{
	if (text[ft_strlen(text) - 1] == LABEL_CHAR)
		lstlabel = ft_lstlabelorigin(lstlabel, text, report);
	return (lstlabel);
}

int			ft_write_opcode(int fdout, char **tabtext, int i,
			t_ggeneral *report)
{
	int		j;
	t_op	*op;

	j = 0;
	op = get_op_tab();
	while (j < 16)
	{
		if (ft_strcmp(tabtext[i], op[j].op) == 0)
		{
			report->placeopcode = report->compt;
			ft_octet_one(fdout, op[j].bin, &report->compt);
			if (op[j].octet_param == 1)
				ft_octet_one(fdout, ft_octet_param(tabtext, i + 1,
				op[j].nb_arg), &report->compt);
			report->tmp = op[j].dir_size;
			return (op[j].nb_arg);
		}
		j++;
	}
	return (0);
}

void		ft_write_registre(int fdout, char *text, t_ggeneral *report)
{
	if (text[0] == REGISTER_CHAR)
	{
		text[0] = ' ';
		ft_octet_one(fdout, ft_atoi(text), &report->compt);
		text[0] = REGISTER_CHAR;
	}
}

t_labelg	*ft_write_indirect(int fdout, char *text, t_ggeneral *report,
	t_labelg *lstlabel)
{
	if (ft_isnumber(text) == 1)
		ft_octet_two(fdout, ft_atoi(text), &report->compt);
	else if (text[0] == LABEL_CHAR)
	{
		ft_octet_two(fdout, 0, &report->compt);
		lstlabel = ft_lstlabelind(lstlabel, text, report);
	}
	return (lstlabel);
}

t_labelg	*ft_write_direct(int fdout, char *text, t_ggeneral *report,
	t_labelg *lstlabel)
{
	if (text[0] == DIRECT_CHAR && ft_isnumber(text + 1) == 1)
	{
		text[0] = ' ';
		if (report->tmp == 1)
			ft_octet_two(fdout, ft_atoi(text), &report->compt);
		else
			ft_octet_four(fdout, ft_atoi(text), &report->compt);
		text[0] = DIRECT_CHAR;
	}
	else if (text[0] == DIRECT_CHAR && text[1] == LABEL_CHAR)
	{
		if (report->tmp == 1)
		{
			ft_octet_two(fdout, 0, &report->compt);
			lstlabel = ft_lstlabeldir(lstlabel, text, 2, report);
		}
		else
		{
			ft_octet_four(fdout, 0, &report->compt);
			lstlabel = ft_lstlabeldir(lstlabel, text, 4, report);
		}
	}
	return (lstlabel);
}
