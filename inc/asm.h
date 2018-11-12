/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 12:01:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:03:37 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <sys/types.h>
# define USAGE "USAGE :\n./asm file.cor"
# include <errno.h>

typedef struct	s_env
{
	t_op	*op_tab;
	t_ntree	*ast;
	char 	*name;
	char	*comment;
}				t_env;

t_env	g_env;

void	init(void);
void	lexer(int fd);
void	parse(int fd);
void	ft_exit_asm(char *msg);
t_op	*get_op_tab(void);

#endif
