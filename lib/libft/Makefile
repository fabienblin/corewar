# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2017/11/28 17:35:55 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/15 17:06:06 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

SRC_DIR =	./src/

PRINTF_DIR = ./src/ft_printf/

OBJ_DIR =	./obj/

INC_DIR =	./inc/

NAME =		libft.a

INC_PF = ./inc/ft_printf.h

INC_GNL = ./inc/get_next_line.h

INC_LIB = ./inc/libft.h

FT_PRINTF =	ft_constuctors.c	ft_destructors.c	ft_parse.c	ft_printf.c	\
			ft_format_setters.c	ft_itoa_type.c		ft_preci_tostring.c		\
			ft_ptoa.c			ft_strgen.c			ft_puttostring.c		\
			ft_unicode.c		ft_type_tostring.c	ft_width_tostring.c		\
			ft_flags_tostring.c	ft_format_setters_ext.c						\
			ft_itoa_type_ext.c	ft_type_tostring_ext.c


FABLIN =	ft_exit.c		ft_realloc.c	ft_lstpush.c	ft_lstdup.c		\
			ft_swapptr.c	get_next_line.c	ft_strjoinfree.c				\
			ft_itoa_base.c	ft_abs.c		ft_strtolower.c	ft_strrealloc.c	\
			ft_bresenham.c	ft_grid.c		ft_point.c		ft_segment.c	\
			ft_ntree.c		ft_strfreejoin.c				ft_lstlen.c		\
			ft_strsplit_whitespace.c		ft_iswhitespace.c

FPUPIER =	ft_wstrnew.c	ft_wstrlen.c	ft_wstrcpy.c	ft_wstrcat.c	\
			ft_wcharlen.c	ft_uitoa_base.c	ft_strndup.c	ft_strisxdigit.c\
			ft_strisupper.c	ft_strisspace.c	ft_strisprint.c	ft_strislower.c	\
			ft_strisdigit.c	ft_strisdigit_pos_neg.c			ft_strisascii.c	\
			ft_strisalpha.c	ft_strisalnum.c	ft_savetext.c	ft_revstr.c		\
			ft_revnstr.c	ft_putwstr.c	ft_putwchar.c	ft_memjoin.c	\
			ft_memcat.c		ft_lstsplit.c	ft_lstndup.c	ft_lstncat.c	\
			ft_lstisdigit.c	ft_lstisalpha.c	ft_lstisalnum.c	ft_lstfree.c	\
			ft_lstcat.c		ft_limits.c		ft_isxdigit.c	ft_isupper.c	\
			ft_isspace.c	ft_islower.c	ft_isgraph.c	ft_iscntrl.c	\
			ft_isblank.c	ft_digitlenneg.c				ft_digitlen.c

BONUS =		ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		\
			ft_lstiter.c	ft_lstmap.c

CFILES =	ft_memset.c		ft_strcat.c		ft_isdigit.c	ft_striter.c	\
			ft_putchar.c 	ft_bzero.c		ft_strncat.c	ft_isalnum.c	\
			ft_striteri.c	ft_putstr.c		ft_memcpy.c		ft_strlcat.c	\
			ft_isascii.c	ft_strmap.c		ft_putendl.c	ft_memccpy.c	\
			ft_strchr.c		ft_isprint.c	ft_strmapi.c	ft_putnbr.c		\
			ft_memmove.c	ft_strrchr.c	ft_toupper.c	ft_strequ.c		\
			ft_putchar_fd.c	ft_memchr.c		ft_strstr.c		ft_tolower.c	\
			ft_strnequ.c	ft_putstr_fd.c	ft_memcmp.c		ft_strnstr.c	\
			ft_memalloc.c	ft_strsub.c		ft_putendl_fd.c	ft_strlen.c		\
			ft_strcmp.c		ft_memdel.c		ft_strjoin.c	ft_putnbr_fd.c	\
		 	ft_strdup.c		ft_strncmp.c	ft_strnew.c		ft_strtrim.c	\
			ft_strcpy.c		ft_atoi.c		ft_strdel.c		ft_strsplit.c	\
			ft_strncpy.c	ft_isalpha.c	ft_strclr.c		ft_itoa.c		\
			ft_isnumber.c	ft_countchar.c	ft_strsupchr.c					\
			ft_strsplitwhitespace.c			ft_free_strsplit.c				\
			$(BONUS)		$(FABLIN)		$(FPUPIER)

SOURCES =	$(addprefix $(SRC_DIR), $(CFILES)) $(addprefix $(PRINTF_DIR), $(FT_PRINTF))

OFILES =	$(CFILES:.c=.o) $(FT_PRINTF:.c=.o)

OBJECTS =	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo "===> LIBFT HAS BEEN COMPILED <==="

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC_GNL) $(INC_LIB)
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)%.o : $(PRINTF_DIR)%.c $(INC_PF)
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean : obj
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re :
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make

.PHONY: all clean fclean re obj
