/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_savetext.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:47:26 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 18:47:26 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_savetext(char **savetext, char *line)
{
	char	*tmpfree;

	if (*savetext == NULL)
	{
		*savetext = (char*)malloc(sizeof(char) * 1);
		if (*savetext == NULL)
			return (NULL);
		*savetext[0] = '\0';
	}
	tmpfree = *savetext;
	*savetext = ft_strjoin(*savetext, line);
	free(tmpfree);
	tmpfree = NULL;
	tmpfree = *savetext;
	*savetext = ft_strjoin(*savetext, "\n");
	free(tmpfree);
	tmpfree = NULL;
	return (NULL);
}
