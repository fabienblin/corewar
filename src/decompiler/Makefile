# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/10/08 18:51:13 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/17 16:17:11 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

DEC		=	../../decompiler

DEC_SRC_DIR =	./

DEC_OBJ_DIR =	../../dec_obj/

DEC_CFILES =	analyze_octet.c	fileout_cor.c	main.c		\
				op.c			other.c			secure_h.c	\
				write_decompiler.c

DEC_SOURCES =	$(addprefix $(DEC_SRC_DIR), $(DEC_CFILES))

DEC_OFILES =	$(DEC_CFILES:.c=.o)

DEC_OBJECTS =	$(addprefix $(DEC_OBJ_DIR), $(DEC_OFILES))

INC_DEC = $(INC_DIR)decompiler.h $(INC_DIR)op.h

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	../../inc/

LIBFT = ../../lib/libft/libft.a

all : $(DEC_OBJ_DIR) $(DEC)

$(DEC) : $(DEC_OBJECTS) $(LIBFT)
	gcc $(FLAGS) $(DEC_OBJECTS) -L ../../lib/libft/ -lft -o $(DEC)

$(DEC_OBJ_DIR)%.o : $(DEC_SRC_DIR)%.c $(INC_DEC)
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(DEC_OBJ_DIR) :
	@mkdir -p $(DEC_OBJ_DIR)

clean : obj
	@rm -rf $(DEC_OBJ_DIR)

fclean : obj
	@rm -f $(DEC)
	@rm -rf $(DEC_OBJ_DIR)

re :
	@rm -f $(DEC)
	@rm -rf $(DEC_OBJ_DIR)
	@make

debug :
	gcc -ggdb $(DEC_SOURCES) ../../lib/libft/libft.a -I ../../lib/libft/inc -I $(INC_DIR) -o asm_debug
	lldb ./asm_debug ../../test.s

.PHONY: all clean fclean re obj
