/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   generator_body.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 18:22:53 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 16:08:27 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static void		ft_write_adress_two(int fdout, t_labelg *tmporigin,
				t_labelg *tmp)
{
	int i;

	i = 0;
	lseek(fdout, tmp->place, SEEK_SET);
	if (tmp->size_octet == 4)
		ft_octet_four(fdout, tmporigin->placeopcode - tmp->placeopcode, &i);
	else
		ft_octet_two(fdout, tmporigin->placeopcode - tmp->placeopcode, &i);
}

static void		ft_write_adress(int fdout, t_labelg *lstlabel)
{
	t_labelg	*tmporigin;
	t_labelg	*tmp;

	tmporigin = lstlabel;
	while (tmporigin != NULL)
	{
		if (tmporigin->type == 'O')
		{
			tmp = lstlabel;
			while (tmp != NULL)
			{
				if (ft_strcmp(tmporigin->name, tmp->name) == 0 &&
				tmp->type != 'O')
					ft_write_adress_two(fdout, tmporigin, tmp);
				tmp = tmp->next;
			}
		}
		tmporigin = tmporigin->next;
	}
}

static void		ft_write_body_two(int *k, int *nbre_arg)
{
	if (*k == *nbre_arg && *k != 0)
	{
		*k = 0;
		*nbre_arg = 0;
	}
}

static t_labelg	*ft_write_body(int fdout, char **tabtext, t_ggeneral *report,
	t_labelg *lstlabel)
{
	int		i;
	int		k;
	int		nbre_arg;

	i = 0;
	k = 0;
	nbre_arg = 0;
	while (tabtext[i] != NULL)
	{
		if (nbre_arg != 0)
		{
			ft_write_registre(fdout, tabtext[i], report);
			lstlabel = ft_write_indirect(fdout, tabtext[i], report, lstlabel);
			lstlabel = ft_write_direct(fdout, tabtext[i], report, lstlabel);
			k++;
		}
		if (nbre_arg == 0)
		{
			lstlabel = ft_write_label(lstlabel, tabtext[i], report);
			nbre_arg = ft_write_opcode(fdout, tabtext, i, report);
		}
		ft_write_body_two(&k, &nbre_arg);
		i++;
	}
	return (lstlabel);
}

void			ft_generator_body(int fdin, int fdout, t_ggeneral *report)
{
	char		*line;
	char		*savetext;
	char		**tabtext;
	t_labelg	*lstlabel;

	line = NULL;
	savetext = NULL;
	tabtext = NULL;
	lstlabel = NULL;
	while (get_next_line(fdin, &line) == 1)
	{
		ft_delete_comment(line);
		ft_savetext(&savetext, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	tabtext = ft_strsplitwhitespace(savetext, SEPARATOR_CHAR);
	lstlabel = ft_write_body(fdout, tabtext, report, lstlabel);
	ft_write_adress(fdout, lstlabel);
	ft_lstlabelfree(&lstlabel);
	ft_free_strsplit(&tabtext);
	ft_strdel(&savetext);
}
