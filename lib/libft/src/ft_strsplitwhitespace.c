/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplitwhitespace.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 13:12:19 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:12:24 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compt(char const *s, char c)
{
	int		i;
	int		compt;
	int		mot;

	i = 0;
	compt = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (mot == 0 && s[i] != c && s[i] != ' ' && s[i] != '\t' &&
		s[i] != '\r' && s[i] != '\v' && s[i] != '\f' && s[i] != '\n')
		{
			mot = 1;
			compt++;
		}
		else if (mot == 1 && (s[i] == c || s[i] == ' ' || s[i] == '\t' ||
		s[i] == '\r' || s[i] == '\v' || s[i] == '\f' || s[i] == '\n'))
		{
			mot = 0;
		}
		i++;
	}
	return (compt);
}

static size_t	ft_taillelimit(char const *s, char c, int *j)
{
	size_t	len;

	len = 0;
	while (s[*j] != c && s[*j] != ' ' && s[*j] != '\t' && s[*j] != '\r' &&
	s[*j] != '\v' && s[*j] != '\f' && s[*j] != '\n' && s[*j] != '\0')
	{
		len++;
		*j = *j + 1;
	}
	return (len);
}

char			**ft_strsplitwhitespace(char const *s, char c)
{
	int		nbremot;
	char	**philip;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nbremot = ft_compt(s, c);
	philip = (char **)malloc(sizeof(char *) * (nbremot + 1));
	if (philip == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (i < nbremot)
	{
		while ((s[j] == c || s[j] == ' ' || s[j] == '\t' || s[j] == '\r' ||
		s[j] == '\v' || s[j] == '\f' || s[j] == '\n') && s[j] != '\0')
			j++;
		philip[i] = ft_strsub(s, j, ft_taillelimit(s, c, &j));
		if (philip[i] == NULL)
			return (NULL);
		i++;
	}
	philip[i] = NULL;
	return (philip);
}
