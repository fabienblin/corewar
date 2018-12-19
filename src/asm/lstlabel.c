/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstlabel.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 12:44:38 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 12:46:30 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_labelg	*ft_lstlabelorigin(t_labelg *lstlabel, char *label,
			t_ggeneral *report)
{
	t_labelg	*tmp;
	t_labelg	*maillon;

	maillon = (t_labelg*)malloc(sizeof(t_labelg));
	if (maillon == NULL)
		return (NULL);
	maillon->name = ft_strsub(label, 0, ft_strlen(label) - 1);
	maillon->type = 'O';
	maillon->place = 0;
	maillon->size_octet = 0;
	maillon->placeopcode = report->compt;
	maillon->next = NULL;
	if (lstlabel == NULL)
		return (maillon);
	tmp = lstlabel;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = maillon;
	return (lstlabel);
}

t_labelg	*ft_lstlabelind(t_labelg *lstlabel, char *label, t_ggeneral *report)
{
	t_labelg	*tmp;
	t_labelg	*maillon;

	maillon = (t_labelg*)malloc(sizeof(t_labelg));
	if (maillon == NULL)
		return (NULL);
	maillon->name = ft_strsub(label, 1, ft_strlen(label));
	maillon->type = 'I';
	maillon->place = report->compt - 2;
	maillon->size_octet = 2;
	maillon->placeopcode = report->placeopcode;
	maillon->next = NULL;
	if (lstlabel == NULL)
		return (maillon);
	tmp = lstlabel;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = maillon;
	return (lstlabel);
}

t_labelg	*ft_lstlabeldir(t_labelg *lstlabel, char *label, int size_octet,
		t_ggeneral *report)
{
	t_labelg *tmp;
	t_labelg *maillon;

	maillon = (t_labelg*)malloc(sizeof(t_labelg));
	if (maillon == NULL)
		return (NULL);
	maillon->name = ft_strsub(label, 2, ft_strlen(label) - 2);
	maillon->type = 'D';
	maillon->place = report->compt - size_octet;
	maillon->size_octet = size_octet;
	maillon->placeopcode = report->placeopcode;
	maillon->next = NULL;
	if (lstlabel == NULL)
		return (maillon);
	tmp = lstlabel;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = maillon;
	return (lstlabel);
}

void		ft_lstlabelfree(t_labelg **lstlabel)
{
	t_labelg *tmp;

	while (*lstlabel != NULL)
	{
		tmp = (*lstlabel)->next;
		free((*lstlabel)->name);
		(*lstlabel)->name = NULL;
		free(*lstlabel);
		*lstlabel = NULL;
		*lstlabel = tmp;
	}
}

int			ft_hashtag_header(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\n')
	{
		i++;
	}
	return (i);
}
