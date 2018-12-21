/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fblin <fblin@student.42.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/01/02 13:22:38 by fblin        #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:23:00 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100

# include <fcntl.h>
# include "libft.h"

typedef struct	s_reader
{
	int		fd;
	char	*prev;
	int		line_n;
}				t_reader;

typedef struct	s_gnl
{
	int				fd;
	char			*str;
	unsigned int	size;
	unsigned int	nb;
	char			*endl;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(int const fd, char **line);
char			*ft_strfreejoin(char *s1, char *s2);

#endif
