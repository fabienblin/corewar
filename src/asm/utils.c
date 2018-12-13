/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 15:27:37 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 18:31:09 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	trim_whitespace(char **str)
{
	char	*start;
	char	*end;
	char	*trim;

	if (!str || !*str)
		return ;
	start = *str;
	while (*start && ft_iswhitespace(*start))
		start++;
	end = &start[ft_strlen(start) - 1];
	while (end > start && ft_iswhitespace(*end))
		end--;
	if (start != *str || end != &str[0][ft_strlen(*str) - 1])
	{
		trim = ft_strsub(*str, start - *str, end - start + 1);
		ft_strdel(str);
		*str = trim;
	}
}

t_op	*get_op(char *opcode)
{
	t_op	*op;
	int		i;

	op = NULL;
	i = 0;
	while (i < REG_NUMBER)
	{
		if (!ft_strcmp(opcode, get_op_tab()[i].op))
		{
			op = &get_op_tab()[i];
			break ;
		}
		i++;
	}
	return (op);
}

int		count_split(char **split)
{
	int count;

	count = 0;
	while (split && *split)
	{
		count++;
		split++;
	}
	return (count);
}

void	freesplit(char ***split)
{
	char	**tmp;

	tmp = *split;
	if (!split || !tmp)
		return ;
	while (*tmp)
	{
		ft_strdel(tmp);
		tmp++;
	}
	free(*tmp);
	free(*split);
	*split = NULL;
}
