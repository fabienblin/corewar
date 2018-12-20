/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   decompiler.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 22:21:00 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 22:24:25 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DECOMPILER_H
# define DECOMPILER_H
# include "libft.h"
# include "op.h"

typedef struct		s_analyze
{
	int				opcode;
	int				state;
	int				param1_nbre;
	int				param2_nbre;
	int				param3_nbre;
	int				compt;
	int				octet_param;
	char			param1_type;
	char			param2_type;
	char			param3_type;
}					t_analyze;

typedef struct		s_bit_octetparam
{
	unsigned		b4	: 2;
	unsigned		b3	: 2;
	unsigned		b2	: 2;
	unsigned		b1	: 2;
}					t_bitoctetparam;

t_op				*get_op_tab(void);
void				ft_fileout_cor(int fdin, char *filein);
int					ft_analyze_octet(int init, t_analyze *myoctet, int nbre);
void				ft_write_dec_body(int fdout, t_analyze myoctet);
int					ft_analyze_octet_param(t_analyze *myoctet, int nbre);
int					ft_param(t_analyze *myoctet, int nbre, char param_type,
					int param_nbre);
int					ft_secure_h(void);

#endif
