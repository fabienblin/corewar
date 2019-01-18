#  ************************************************************************** #
#                                                           LE - /            #
#                                                               /             #
#    Makefile                                         .::    .:/ .      .::   #
#                                                  +:+:+   +:    +:  +:+:+    #
#    By: vsteyaer <vsteyaer@student.le-101.fr>      +:+   +:    +:    +:+     #
#                                                  #+#   #+    #+    #+#      #
#    Created: 2018/11/08 14:44:31 by vsteyaer     #+#   ##    ##    #+#       #
#    Updated: 2019/01/18 09:13:09 by vsteyaer    ###    #+. /#+    ###.fr      #
#                                                          /                  #
#                                                         /                   #
#  ************************************************************************** #

SRC_DIR =	./src/

PRINTF_DIR = ./src/ft_printf/

OBJ_DIR =	./obj/

INC_DIR =	./inc/

NAME =		libft.a

INC_PF = ./inc/ft_printf.h

INC_LIB = ./inc/libft.h

FT_PRINTF = ft_b.c \
		    ft_c.c \
	    	ft_color.c \
			ft_conversion.c \
		    ft_d_i.c \
		    ft_gestion.c \
		    ft_lx.c \
		    ft_n.c \
		    ft_o.c \
		    ft_p.c \
		    ft_pourcent.c \
		    ft_printf.c \
		    ft_read_format.c \
		    ft_read_params.c \
		    ft_s.c \
		    ft_switch.c \
		    ft_u.c \
		    ft_wchar.c \
		    ft_x.c

CFILES =  	ft_atoi.c \
		    ft_bzero.c \
		    ft_isalnum.c \
	    	ft_isalpha.c \
		           ft_isascii.c \
		           ft_isblank.c \
		           ft_iscntrl.c \
		           ft_isdigit.c \
		           ft_isgraph.c \
		           ft_islower.c \
		           ft_isprint.c \
		           ft_isspace.c \
		           ft_isupper.c \
		           ft_isxdigit.c \
		           ft_itoa.c \
		           ft_lstadd.c \
		           ft_lstcat.c \
		           ft_lstdel.c \
		           ft_lstdelone.c \
		           ft_lstdup.c \
		           ft_lstfree.c \
		           ft_lstisalnum.c \
		           ft_lstisalpha.c \
		           ft_lstisdigit.c \
		           ft_lstiter.c \
		           ft_lstlen.c \
		           ft_lstmap.c \
		           ft_lstncat.c \
		           ft_lstndup.c \
		           ft_lstnew.c \
		           ft_lstsplit.c \
		           ft_memalloc.c \
		           ft_memcat.c \
		           ft_memccpy.c \
		           ft_memchr.c \
		           ft_memcmp.c \
		           ft_memcpy.c \
		           ft_memdel.c \
		           ft_memjoin.c \
		           ft_memmove.c \
		           ft_memset.c \
		           ft_putchar.c \
		           ft_putchar_fd.c \
		           ft_putendl.c \
		           ft_putendl_fd.c \
		           ft_putnbr.c \
		           ft_putnbr_fd.c \
		           ft_putstr.c \
		           ft_putstr_fd.c \
		           ft_strcat.c \
		           ft_strchr.c \
		           ft_strclr.c \
		           ft_strcmp.c \
		           ft_strcpy.c \
		           ft_strdel.c \
		           ft_strdup.c \
		           ft_strequ.c \
		           ft_strisalnum.c \
		           ft_strisalpha.c \
		           ft_strisascii.c \
		           ft_strisdigit.c \
		           ft_strisdigit_pos_neg.c \
		           ft_strislower.c \
		           ft_strisprint.c \
		           ft_strisspace.c \
		           ft_strisupper.c \
		           ft_strisxdigit.c \
		           ft_striter.c \
		           ft_striteri.c \
		           ft_strjoin.c \
		           ft_strlcat.c \
		           ft_strlen.c \
		           ft_strmap.c \
		           ft_strmapi.c \
		           ft_strncat.c \
		           ft_strncmp.c \
		           ft_strncpy.c \
		           ft_strndup.c \
		           ft_strnequ.c \
		           ft_strnew.c \
		           ft_strnstr.c \
		           ft_strrchr.c \
		           ft_strsplit.c \
		           ft_strstr.c \
		           ft_strsub.c \
		           ft_strtrim.c \
		           ft_tolower.c \
		           ft_toupper.c \
		           ft_uitoa_base.c \
		           ft_realloc.c \
		           ft_savetext.c \
		           ft_revstr.c \
		           ft_revnstr.c \
				   ft_limits.c \
				   ft_digitlen.c \
				   ft_digitlenneg.c \
		           get_next_line.c

SOURCES =	$(addprefix $(SRC_DIR), $(CFILES)) $(addprefix $(PRINTF_DIR), $(FT_PRINTF))

OFILES =	$(CFILES:.c=.o) $(FT_PRINTF:.c=.o)

OBJECTS =	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo "===> LIBFT HAS BEEN COMPILED !!! <==="

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC_LIB)
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
