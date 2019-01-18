/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 12:01:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 19:11:29 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <sys/types.h>
# define USAGE "USAGE :\n./asm file.s"
# define VALID_HEADER (2)
# include <errno.h>

typedef struct		s_label
{
	char	*name;
	int		is_declared;
	int		is_used;
}					t_label;

typedef struct		s_labelg
{
	char			*name;
	char			type;
	int				place;
	int				size_octet;
	int				placeopcode;
	struct s_labelg	*next;
}					t_labelg;

typedef struct		s_ggeneral
{
	int				compt;
	int				tmp;
	int				tmpheader;
	int				placeopcode;
	unsigned int	placement_size;
	unsigned int	placement_beginprog;

}					t_ggeneral;

typedef struct		s_champbits
{
	unsigned	b4 : 8;
	unsigned	b3 : 8;
	unsigned	b2 : 8;
	unsigned	b1 : 8;
}					t_champbits;

void				init(void);
void				lexer(int fd);
void				parse(int fd);
void				ft_exit_asm(char *msg);
t_op				*get_op_tab(void);
void				freesplit(char ***split);

/*
**arg_types.c
*/
int					is_label_str(char *str);
int					is_t_reg(char *str, int op_arg);
int					is_t_dir(char *str, int op_arg);
int					is_t_ind(char *str, int op_arg);
int					is_t_lab(char *str, int op_arg);

/*
**utils.c
*/
void				trim_whitespace(char **str);
t_op				*get_op(char *opcode);
int					count_split(char **split);

/*
**label.c
*/
t_label				*new_label(char *name, int is_declared, int is_used);
void				del_label(void *label, size_t size);

/*
**lexer_asm_1.c & lexer_asm_2.c
*/
int					check_line(char *line, t_list **labels);
void				remove_comment(char **line);
int					valid_args(char *line, t_op *op, t_list **labels);
char				*get_op_on_line(char *line, t_list **labels, char **split);

/*
**lexer_header_1/2.c
*/
int					check_header(int fd);
void				skip_empty_lines(int fd, char **line);

/*
**generator
*/
int					ft_generator(int fdin, char **argv);
void				ft_generator_header(int fd, int fdout, t_ggeneral *report);
void				ft_octet_one(int fdout, int nbre, int *compt);
void				ft_octet_two(int fdout, int nbre, int *compt);
void				ft_octet_four(int fdout, int nbre, int *compt);
char				*ft_savetext(char **savetext, char *line);
void				ft_generator_body(int fdin, int fdout, t_ggeneral *report);
t_labelg			*ft_lstlabelorigin(t_labelg *lstlabel, char *label,
					t_ggeneral *report);
t_labelg			*ft_lstlabelind(t_labelg *lstlabel, char *label,
					t_ggeneral *report);
t_labelg			*ft_lstlabeldir(t_labelg *lstlabel, char *label,
					int size_octet, t_ggeneral *report);
t_labelg			*ft_write_label(t_labelg *lstlabel, char *text,
					t_ggeneral *report);
int					ft_write_opcode(int fdout, char **tabtext, int i,
					t_ggeneral *report);
void				ft_write_registre(int fdout, char *text,
					t_ggeneral *report);
t_labelg			*ft_write_indirect(int fdout, char *text,
					t_ggeneral *report, t_labelg *lstlabel);
t_labelg			*ft_write_direct(int fdout, char *text, t_ggeneral *report,
					t_labelg *lstlabel);
int					ft_octet_param(char **tabtext, int i, int nb_arg);
void				ft_delete_comment(char *line);
void				ft_lstlabelfree(t_labelg **lstlabel);
int					ft_hashtag_header(char *tmp);
int					ft_comment_header(char *line);
int					ft_secure_h(void);
#endif
