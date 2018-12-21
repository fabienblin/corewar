/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:17:53 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>

# include "get_next_line.h"
# include "ft_printf.h"

# define INF (0x7FFFFFFF)

# define STDIN 0
# define STDOUT 1
# define STDERR 1

# define UNSIGNED 0
# define SIGNED	1

/*
**FIRST PART
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char*big, const char *little, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**SECOND PART
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_grid
{
	int		**data;
	int		x;
	int		y;
	int		size;
}				t_grid;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_segment
{
	t_point *a;
	t_point *b;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
}				t_seg;

typedef struct	s_ntree
{
	t_point			*coord;
	char			*name;
	int				depth;
	t_list			*sons;
	int				nbsons;
}				t_ntree;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**FABLIN
*/
void			ft_exit(char *err_message);
void			*ft_realloc(void **mem, size_t size);
void			ft_lstpush(t_list **alst, t_list *new);
t_list			*ft_lstdup(t_list *lst);
void			ft_swapptr(void **a, void **b);
int				get_next_line(int fd, char **line);
char			*ft_strjoinfree(char *s1, char *s2);
char			*ft_itoa_base(int n, int base);
int				ft_abs(int x);
char			*ft_strtolower(char *str);
char			*ft_strrealloc(char **str, size_t size);
void			ft_delgrid(t_grid **grid);
void			ft_delsegment(t_seg **seg);
void			ft_delpoint(t_point **p);
void			ft_delntree(t_ntree **t);
t_grid			*ft_newgrid(int x, int y);
t_seg			*ft_newsegment(t_point *a, t_point *b);
t_point			*ft_newpoint(int x, int y);
t_ntree			*ft_newntree(char *name, t_point *coord, int dept, t_list *son);
int				ft_lstlen(t_list *sons);
void			bresenham(t_grid *grid, t_seg *seg, int val);
int				ft_iswhitespace(char c);
char			**ft_strsplit_whitespace(char const *s);

/*
**SLATCHMA
*/
int				ft_isnumber(char *str);
int				ft_countchar(char *str, char c);
int				ft_strsupchr(const char *s, int c);
char			**ft_strsplitwhitespace(char const *s, char c);
void			ft_free_strsplit(char ***split);

/*
**FPUPIER
*/
t_list			*ft_lstsplit(char const *s, char c);
int				ft_strisalpha(const char *s);
int				ft_strisdigit(const char *s);
int				ft_strisdigit_pos_neg(const char *s);
int				ft_strisalnum(const char *s);
int				ft_strisascii(const char *s);
int				ft_strisprint(const char *s);
int				ft_strisspace(const char *s);
int				ft_strisupper(const char *s);
int				ft_strislower(const char *s);
int				ft_strisxdigit(const char *s);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_isxdigit(int c);
void			ft_lstfree(t_list *lst);
t_list			*ft_lstndup(const t_list *lst, size_t n);
t_list			*ft_lstcat(t_list *lst_dst, t_list *lst_src);
t_list			*ft_lstncat(t_list *lst_dst, t_list *lst_src, size_t n);
int				ft_lstisalpha(const t_list *list);
int				ft_lstisdigit(const t_list *list);
int				ft_lstisalnum(const t_list *list);
int				ft_digitlenneg(long long n);
int				ft_digitlen(long long n);
int				ft_limits(char *str, int sign, long long limit);
size_t			ft_wcharlen(wchar_t c);
wchar_t			*ft_wstrcat(wchar_t *ws1, wchar_t *ws2);
wchar_t			*ft_wstrcpy(wchar_t *wdst, wchar_t *wsrc);
size_t			ft_wstrlen(wchar_t *wstr);
wchar_t			*ft_wstrnew(size_t size);
int				ft_putwchar(wchar_t wc);
void			ft_putwstr(wchar_t *str);
char			*ft_savetext(char **savetext, char *line);
char			*ft_revstr(char *str);
char			*ft_revnstr(char *str, int oct);
void			*ft_memcat(void *dst, size_t start, const void *src,
				size_t len_src);
#endif
