/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 12:01:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 15:37:26 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <sys/types.h>
# define USAGE "USAGE :\n./asm file.s"
# include <errno.h>

typedef struct	s_label
{
	char	*name;
	int		is_declared;
	int		is_used;
}				t_label;

void	init(void);
void	lexer(int fd);
void	parse(int fd);
void	ft_exit_asm(char *msg);
t_op	*get_op_tab(void);
void	freesplit(char ***split);

//arg_types.c
int		is_label_str(char *str);
int		is_t_reg(char *str, int op_arg);
int		is_t_dir(char *str, int op_arg);
int		is_t_ind(char *str, int op_arg);
int		is_t_lab(char *str, int op_arg);

//utils.c
void	trim_whitespace(char **str);
t_op	*get_op(char *opcode);
int		count_split(char **split);

//label.c
t_label	*new_label(char *name, int is_declared, int is_used);
void	del_label(t_label **label);

//lexer_ext_1.c & lexer_ext_2.c
int		check_line(char **line, int line_n, int *header, t_list **labels);
t_op	*valid_op_lab(char *line, int line_n, t_list **labels);
int		valid_args(char *line, int line_n, t_op *op, t_list **labels);
#endif
