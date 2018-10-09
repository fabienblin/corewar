/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format_setters_ext.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/11 19:01:17 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 19:02:29 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_override_flags(t_format *f)
{
	if (f->flags[0] == '+' && f->flags[4] == ' ')
		f->flags[4] = -1;
	if (f->flags[2] == '0' && f->flags[1] == '-')
		f->flags[2] = -1;
}

char	*ft_find_flag_zero(char *c)
{
	if (c && *c)
	{
		while (*c)
		{
			if (ft_isdigit(*c) && *c != '0')
				return (NULL);
			else if (*c == '0')
				return (c);
			c++;
		}
	}
	return (NULL);
}
