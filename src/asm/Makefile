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

ASM		=	../../asm

ASM_SRC_DIR =	./

ASM_OBJ_DIR =	../../asm_obj/

ASM_CFILES =	main.c				exit.c					lexer.c \
				op.c				arg_types.c 			utils.c \
				label.c				lexer_asm_1.c			lexer_asm_2.c \
				lexer_header_1.c	lexer_header_2.c		generator.c	\
				generator_header.c	write_octet.c			other.c	\
				generator_body.c	lstlabel.c				write_param.c \
				secure_h.c

ASM_SOURCES =	$(addprefix $(ASM_SRC_DIR), $(ASM_CFILES))

ASM_OFILES =	$(ASM_CFILES:.c=.o)

ASM_OBJECTS =	$(addprefix $(ASM_OBJ_DIR), $(ASM_OFILES))

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	../../inc/

INC_ASM = $(INC_DIR)asm.h $(INC_DIR)op.h

LIBFT = ../../lib/libft/libft.a

all : $(ASM_OBJ_DIR) $(ASM)

$(ASM) : $(ASM_OBJECTS) $(LIBFT)
	gcc $(FLAGS) $(ASM_OBJECTS) -L ../../lib/libft/ -lft -o $(ASM)

$(ASM_OBJ_DIR)%.o : $(ASM_SRC_DIR)%.c $(INC_ASM)
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(ASM_OBJ_DIR) :
	@mkdir -p $(ASM_OBJ_DIR)

clean : obj
	@rm -rf $(ASM_OBJ_DIR)

fclean : obj
	@rm -f $(ASM)
	@rm -rf $(ASM_OBJ_DIR)

re :
	@rm -f $(ASM)
	@rm -rf $(ASM_OBJ_DIR)
	@make

debug :
	gcc -ggdb $(ASM_SOURCES) ../../lib/libft/libft.a -I ../../lib/libft/inc -I $(INC_DIR) -o asm_debug
	lldb ./asm_debug ../../test.s

.PHONY: all clean fclean re obj
