/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 11:27:02 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 13:48:02 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_find_type(char *str)
{
	char	*type;

	type = str + 1;
	while (*type)
	{
		if (*type == 's' || *type == 'S' || *type == 'p' || *type == 'd' ||
			*type == 'D' || *type == 'i' || *type == 'o' || *type == 'O' ||
			*type == 'u' || *type == 'U' || *type == 'x' || *type == 'X' ||
			*type == 'c' || *type == 'C' || *type == '%')
			return (type + 1);
		else if (ft_isalpha((int)*type) && !(*type == 'h' || *type == 'l' ||
				*type == 'j' || *type == 'z'))
			return (type + 1);
		type++;
	}
	return (NULL);
}

static void	ft_format_push(t_format **alst, t_format *new)
{
	if (!*alst)
		*alst = new;
	else
		ft_format_push(&(*alst)->next, new);
}

t_format	*ft_parse(char *format)
{
	t_format	*format_lst;
	char		*begin;
	char		*end;
	char		*tmp;

	begin = format;
	end = format;
	format_lst = NULL;
	while (*begin)
	{
		if (*begin == '%')
		{
			if (!(end = ft_find_type(begin)))
				end = begin + ft_strlen(begin);
		}
		else if (ft_strchr(begin, '%') == NULL)
			end = begin + ft_strlen(begin);
		else
			end = ft_strchr(begin, '%');
		tmp = ft_strsub(begin, 0, end - begin);
		ft_format_push(&format_lst, ft_new_format(tmp));
		free(tmp);
		begin = end++;
	}
	return (format_lst);
}
