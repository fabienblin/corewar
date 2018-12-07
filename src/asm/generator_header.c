/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   generator_header.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 21:50:12 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 12:44:15 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static int	ft_write_name_cmd(int fdout, char *tmp, t_ggeneral *report)
{
	int compt;
	int len;

	compt = 0;
	len = 0;
	while (tmp[0] != '"')
	{
		tmp++;
		compt++;
	}
	tmp++;
	len = ft_strsupchr(tmp, '"');
	if (tmp[0] != '"')
	{
		write(fdout, tmp, len);
		report->compt = report->compt + len;
	}
	while (report->compt < PROG_NAME_LENGTH + 4)
	{
		ft_octet_one(fdout, 0, &report->compt);
	}
	return (compt + 1 + len);
}

static void	ft_write_comment_cmd_two(int fdout, t_ggeneral *report)
{
	while (report->compt < (report->tmpheader + 4 + COMMENT_LENGTH))
	{
		ft_octet_one(fdout, 0, &report->compt);
	}
	while (report->compt % 16 != 0)
	{
		ft_octet_one(fdout, 0, &report->compt);
	}
}

static void	ft_write_comment_cmd(int fdout, char *tmp, t_ggeneral *report)
{
	int len;

	len = 0;
	while (report->compt % 8 != 0)
	{
		ft_octet_one(fdout, 0, &report->compt);
	}
	report->tmpheader = report->compt;
	report->placement_size = report->compt;
	ft_octet_four(fdout, 0, &report->compt);
	while (tmp[0] != '"')
	{
		tmp++;
	}
	tmp++;
	len = ft_strsupchr(tmp, '"');
	if (tmp[0] != '"')
	{
		write(fdout, tmp, len);
		report->compt = report->compt + len;
	}
	ft_write_comment_cmd_two(fdout, report);
}

static void	ft_write_header(int fdout, char *savetext, t_ggeneral *report)
{
	int		i;
	int		state;
	char	*tmp;

	i = 0;
	state = 0;
	tmp = savetext;
	while (state != -1 && tmp[0] != '\0')
	{
		if (tmp[0] == COMMENT_CHAR)
			tmp = tmp + ft_hashtag_header(tmp);
		if (state == 1 && ft_strncmp(COMMENT_CMD_STRING, tmp,
		ft_strlen(COMMENT_CMD_STRING)) == 0)
		{
			ft_write_comment_cmd(fdout, tmp, report);
			state = -1;
		}
		if (state == 0 && ft_strncmp(NAME_CMD_STRING, tmp,
		ft_strlen(NAME_CMD_STRING)) == 0)
		{
			tmp = tmp + ft_write_name_cmd(fdout, tmp, report);
			state = 1;
		}
		tmp++;
	}
}

void		ft_generator_header(int fdin, int fdout, t_ggeneral *report)
{
	char	*line;
	int		state;
	char	*savetext;

	line = NULL;
	savetext = NULL;
	state = 0;
	while (state != -1 && get_next_line(fdin, &line) == 1)
	{
		ft_savetext(&savetext, line);
		if (state == 1 && ft_countchar(line, '"') == 1)
			state = -1;
		if (state == 0 && ft_strstr(line, COMMENT_CMD_STRING) != NULL)
		{
			state = 1;
			if (ft_countchar(line, '"') == 2)
				state = -1;
			if (ft_comment_header(line) == 1)
				state = 0;
		}
		ft_strdel(&line);
	}
	ft_octet_four(fdout, COREWAR_EXEC_MAGIC, &report->compt);
	ft_write_header(fdout, savetext, report);
	ft_strdel(&savetext);
}
