/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 19:31:54 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# include <wchar.h>
# include <stddef.h>

# include <stdio.h>

# define FLAG "#0-+ "
# define LARGEUR "-123456789*"
# define PRECISION "."
# define TAILLE "hljz"
# define TYPE "sSpdDioOuUxXcCbn%"
# define BASE_2 "01"
# define BASE_8 "01234567"
# define BASE_10 "0123456789"
# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"

typedef enum		e_taille
{
	DEF_TAI, HH, H, L, LL, J, Z
}					t_taille;

typedef enum		e_type
{
	DEF_TYP, S, C, CC, P, D, I, O, U, X, LX, B, N, POURCENT
}					t_type;

typedef struct		s_data
{
	int				l_for;
	char			*s_for;
	int				l_pri;
	char			*s_pri;
	int				pos;
	int				ret;
	int				i;

	int				diese;
	int				moin;
	int				pluss;
	int				espace;
	int				zero;

	int				largeur;
	int				point;
	int				precision;
	enum e_taille	taille;
	enum e_type		type;
	intmax_t		argument;

	int				l_con;
	char			*s_con;
	int				l_lar;
	char			*s_lar;
	int				l_sig;
	char			*s_sig;
	int				l_pre;
	char			*s_pre;
	int				l_val;
	char			*s_val;
	int				l_arg;
	char			*s_arg;
}					t_data;

int					ft_printf(const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);

int					ft_init(const char *format, t_data *data);
int					ft_av_format(t_data *data, unsigned int i);
int					ft_add_caractere(t_data *data);

int					ft_color(t_data *d);
int					ft_read_format(t_data *data, va_list *argv);
int					ft_read_flag(t_data *data);
int					ft_read_largeur(t_data *data, va_list *argv);
int					ft_read_precision(t_data *data, va_list *argv);
int					ft_read_taille(t_data *data);
int					ft_read_type(t_data *data);

int					ft_conversion(t_data *data, va_list *argv);
char				*ft_w_char(t_data *data);
char				*ft_w_string(t_data *data);

int					ft_switch(t_data *data);
int					ft_s(t_data *data);
int					ft_c(t_data *data);
int					ft_p(t_data *data);
int					ft_d_i(t_data *data);
int					ft_u(t_data *data);
int					ft_o(t_data *data);
int					ft_x(t_data *data);
int					ft_lx(t_data *data);
int					ft_b(t_data *data);
int					ft_n(t_data *data);
int					ft_pourcent(t_data *data);
int					ft_arg(t_data *data, va_list *argv, int *ret);
int					ft_init_data(t_data *data);
char				*ft_uitoa_base(uintmax_t nbr, char *base);

#endif
