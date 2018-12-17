/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:50 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_word(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

t_list		*ft_lstsplit(char const *s, char c)
{
	t_list	*new;

	new = NULL;
	if (s == NULL)
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	if ((ft_len_word((const char *)s, c)) != 0)
	{
		if ((new = ft_lstnew(NULL, 0)) == NULL)
			return (NULL);
		new->content = ft_strsub((const char *)s, 0, ft_len_word(s, c));
		new->content_size = ft_len_word((const char *)s, c);
		s += ft_len_word(s, c);
		new->next = ft_lstsplit(s, c);
	}
	return (new);
}
