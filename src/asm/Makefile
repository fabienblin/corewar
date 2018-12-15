# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/10/08 18:51:13 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/15 13:40:14 by fablin      ###    #+. /#+    ###.fr     #
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
				generator_body.c	lstlabel.c				write_param.c

ASM_SOURCES =	$(addprefix $(ASM_SRC_DIR), $(ASM_CFILES))

ASM_OFILES =	$(ASM_CFILES:.c=.o)

ASM_OBJECTS =	$(addprefix $(ASM_OBJ_DIR), $(ASM_OFILES))

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	../../inc/

all : $(ASM_OBJ_DIR) $(ASM)

$(ASM) : $(ASM_OBJECTS)
	gcc $(FLAGS) $(ASM_OBJECTS) -L ../../lib/libft/ -lft -o $(ASM)

$(ASM_OBJ_DIR)%.o : $(ASM_SRC_DIR)%.c
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

.PHONY: all clean fclean re obj
