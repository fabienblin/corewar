/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:56 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:40 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nbr_word(const char *s, char c)
{
	int		nbr;
	int		flag;

	flag = 0;
	nbr = 0;
	while (*s != '\0')
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			nbr++;
		}
		s++;
	}
	return (nbr);
}

static int		ft_len_word(const char *s, char c)
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

char			**ft_strsplit(char const *s, char c)
{
	char	**rep;
	int		nb_word;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_word = ft_nbr_word((const char *)s, c);
	if ((rep = (char **)malloc(sizeof(*rep) * (nb_word + 1))) == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		rep[i] = ft_strsub((const char *)s, 0, ft_len_word((const char *)s, c));
		if (rep[i] == NULL)
			return (NULL);
		s += ft_len_word(s, c);
		i++;
	}
	rep[i] = NULL;
	return (rep);
}
