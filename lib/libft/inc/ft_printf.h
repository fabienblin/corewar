/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:17:06 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 13:54:36 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <locale.h>
# include <stdlib.h>

# include "libft.h"

typedef enum	e_size
{
	HH = 1,
	H = 2,
	LL = 3,
	L = 4,
	J = 5,
	Z = 6
}				t_size;

typedef struct	s_format
{
	struct s_format		*next;
	char				flags[6];
	int					width;
	int					preci;
	int					size;
	char				type;
	char				*tostring;
	void				*arg;
	char				*form;
	int					err;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_printfd(int fd, const char *format, ...);

void			ft_type_uox_tostring(t_format *f, va_list ap);
void			ft_type_di_tostring(t_format *f, va_list ap);
void			ft_type_p_tostring(t_format *f, va_list ap);
int				ft_type_c_tostring(t_format *f, va_list ap);
int				ft_type_s_tostring(t_format *f, va_list ap);

t_format		*ft_new_format(char *substr);
t_format		*ft_parse(char *format);
char			*ft_uintmax_itoa_type(uintmax_t n, char t);
char			*ft_intmax_itoa_type(intmax_t n, char t);
char			*ft_ptoa(void *p);
char			*ft_strgen(int c, int len);
void			ft_del_format_lst(t_format *f);
int				ft_puttostring_fd(t_format *f, int fd);
int				ft_convert_wstr_to_str(char **dst, wchar_t *wstr, int limit);
int				ft_get_type_base(char t);
void			ft_override_flags(t_format *f);
char			*ft_find_flag_zero(char *c);

char			*ft_set_flags(char *c, t_format *f);
char			*ft_set_width(char *c, t_format *f);
char			*ft_set_preci(char *c, t_format *f);
char			*ft_set_size(char *c, t_format *f);
char			*ft_set_type(char *c, t_format *f);
void			ft_set_tostring(t_format *f, va_list ap);

void			ft_preci_tostring(t_format *f);
int				ft_type_tostring(t_format *f, va_list ap);
void			ft_width_tostring(t_format *f);
void			ft_flags_tostring(t_format *f);

void			puttformat(t_format *f);

#endif
