/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_types.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 21:27:34 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 15:49:04 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

int	is_label_str(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_strchr(LABEL_CHARS, (int)*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_t_reg(char *str, int op_arg)
{
	return ((op_arg & T_REG) &&
			(str[0] == REGISTER_CHAR && ft_isdigit(str[1])) &&
			(ft_atoi(&str[1]) > 0 && ft_atoi(&str[1]) <= REG_NUMBER));
}

int	is_t_dir(char *str, int op_arg)
{
	return ((op_arg & T_DIR) && str[0] == DIRECT_CHAR &&
			((ft_isdigit(str[1]) ||
			(str[1] == '-' && ft_isdigit(str[2]))) || (str[1] == LABEL_CHAR &&
			(is_label_str(&str[2])))));
}

int	is_t_ind(char *str, int op_arg)
{
	return ((op_arg & T_IND) &&
			((ft_isdigit(str[0]) || (str[0] == '-' && ft_isdigit(str[1]))) ||
			(str[0] == LABEL_CHAR && is_label_str(&str[1]))));
}

int	is_t_lab(char *str, int op_arg)
{
	return ((op_arg & T_LAB) &&
			(is_label_str(&str[0])));
}
