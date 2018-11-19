/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit_whitespace.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:30 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 16:11:47 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substr(char const *s)
{
	int		i;
	size_t	nb_substr;

	nb_substr = 0;
	if (s)
	{
		i = 0;
		while (s[i])
		{
			while (s[i] && ft_iswhitespace(s[i]))
				i++;
			if (s[i] && !ft_iswhitespace(s[i]))
				nb_substr++;
			while (s[i] && !ft_iswhitespace(s[i]))
				i++;
		}
	}
	return (nb_substr);
}

static size_t	ft_strsub_len(char *s)
{
	size_t	len;

	len = 0;
	while (*s && ft_iswhitespace(*s))
		s++;
	while (*s && !ft_iswhitespace(*s))
	{
		s++;
		len++;
	}
	return (len);
}

static int		ft_nbwhitespaces(char *s)
{
	int skip;

	skip = 0;
	while (*s && ft_iswhitespace(*s))
	{
		skip++;
		s++;
	}
	return (skip);
}

static char		**ft_newsplit(int nb_substr)
{
	char **newsplit;

	if (!(newsplit = (char **)malloc(sizeof(char *) * (nb_substr + 1))))
		return (NULL);
	newsplit[nb_substr] = ((void *)0);
	return (newsplit);
}

char			**ft_strsplit_whitespace(char const *s)
{
	size_t			substr_len;
	unsigned int	split_i;
	char			**split;
	size_t			nb_substr;
	char			*str;

	split = NULL;
	if (s)
	{
		split_i = 0;
		str = (char*)s;
		nb_substr = ft_count_substr(s);
		if (!(split = ft_newsplit(nb_substr)))
			return (NULL);
		while (split_i < nb_substr)
		{
			str += ft_nbwhitespaces(str);
			substr_len = ft_strsub_len(str);
			if (!(split[split_i] = ft_strsub(str, 0, substr_len)))
				return (NULL);
			split_i++;
			str += substr_len;
		}
	}
	return (split);
}
