/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   generator.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 17:48:46 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 16:14:47 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

char		*ft_savetext(char **savetext, char *line)
{
	char *tmpfree;

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

static char	*ft_namefile(char *namein)
{
	int		len;
	char	*nameout;
	int		i;

	i = 0;
	len = ft_strlen(namein);
	nameout = (char*)malloc(sizeof(char) * (len + 3));
	if (nameout == NULL)
		return (NULL);
	while (i < (len - 1))
	{
		nameout[i] = namein[i];
		i++;
	}
	nameout[i] = 'c';
	nameout[i + 1] = 'o';
	nameout[i + 2] = 'r';
	nameout[i + 3] = '\0';
	return (nameout);
}

static void	ft_initreport(t_ggeneral *report)
{
	report->compt = 0;
	report->tmp = 0;
	report->tmpheader = 0;
	report->placement_size = 0;
	report->placement_beginprog = 0;
	report->placeopcode = 0;
}

static void	ft_size(int fdout, t_ggeneral report)
{
	int i;

	i = report.compt - report.placement_beginprog;
	lseek(fdout, report.placement_size, SEEK_SET);
	ft_octet_four(fdout, i, &report.compt);
}

int			ft_generator(int fdin, char **argv)
{
	int			fdout;
	char		*nameout;
	t_ggeneral	report;

	ft_initreport(&report);
	nameout = NULL;
	nameout = ft_namefile(argv[1]);
	fdout = open(nameout, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU
			| S_IRWXG | S_IRWXO);
	ft_generator_header(fdin, fdout, &report);
	report.placement_beginprog = report.compt;
	ft_generator_body(fdin, fdout, &report);
	ft_size(fdout, report);
	close(fdout);
	ft_printf("writing output program to %s\n", nameout);
	ft_strdel(&nameout);
	return (0);
}
