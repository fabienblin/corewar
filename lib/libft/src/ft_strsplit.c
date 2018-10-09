/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:30 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:30 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substr(char const *s, char c)
{
	int		i;
	size_t	nb_substr;

	nb_substr = 0;
	if (s)
	{
		i = 0;
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
				nb_substr++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb_substr);
}

static size_t	ft_strsub_len(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static int		ft_nbwhitespaces(char *s, char c)
{
	int skip;

	skip = 0;
	while (*s && *s == c)
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

char			**ft_strsplit(char const *s, char c)
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
		nb_substr = ft_count_substr(s, c);
		if (!(split = ft_newsplit(nb_substr)))
			return (NULL);
		while (split_i < nb_substr)
		{
			str += ft_nbwhitespaces(str, c);
			substr_len = ft_strsub_len(str, c);
			if (!(split[split_i] = ft_strsub(str, 0, substr_len)))
				return (NULL);
			split_i++;
			str += substr_len;
		}
	}
	return (split);
}
