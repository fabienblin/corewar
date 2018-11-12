# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/10/08 18:51:13 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/11/06 18:19:39 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

COREWAR =	corewar

ASM		=	asm

COR_SRC_DIR =	./src/corewar/

ASM_SRC_DIR =	./src/asm/

COR_OBJ_DIR =	./cor_obj/

ASM_OBJ_DIR =	./asm_obj/

COR_CFILES =	main.c exit.c

ASM_CFILES =	main.c exit.c

COR_SOURCES =	$(addprefix $(COR_SRC_DIR), $(COR_CFILES))

ASM_SOURCES =	$(addprefix $(ASM_SRC_DIR), $(ASM_CFILES))

COR_OFILES =	$(COR_CFILES:.c=.o)

ASM_OFILES =	$(ASM_CFILES:.c=.o)

COR_OBJECTS =	$(addprefix $(COR_OBJ_DIR), $(COR_OFILES))

ASM_OBJECTS =	$(addprefix $(ASM_OBJ_DIR), $(ASM_OFILES))

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	./inc/

all : libft obj $(COREWAR) $(ASM)

$(COREWAR) : $(COR_OBJECTS)
	gcc $(FLAGS) $(COR_OBJECTS) -L ./lib/libft/ -lft -o $(COREWAR)

$(ASM) : $(ASM_OBJECTS)
	gcc $(FLAGS) $(ASM_OBJECTS) -L ./lib/libft/ -lft -o $(ASM)

$(COR_OBJ_DIR)%.o : $(COR_SRC_DIR)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ./lib/libft/inc/

$(ASM_OBJ_DIR)%.o : $(ASM_SRC_DIR)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ./lib/libft/inc/

libft :
	@make -C ./lib/libft

obj :
	@mkdir -p $(COR_OBJ_DIR)
	@mkdir -p $(ASM_OBJ_DIR)

clean : obj
	@make clean -C ./lib/libft/
	@rm -rf $(COR_OBJ_DIR)
	@rm -rf $(ASM_OBJ_DIR)

fclean : obj
	@make fclean -C ./lib/libft/
	@rm -rf $(COREWAR) $(ASM)
	@rm -rf $(COR_OBJ_DIR)
	@rm -rf $(ASM_OBJ_DIR)

re : fclean all

install :
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install npm
	brew install soket.io

test :
	@make -C ./lib/libft
	gcc $(SOURCES) -L ./lib/libft/ -lft -o test_corewar -I $(INC_DIR) -I ./lib/libft/inc/

.PHONY: all clean fclean re libft corewar asm obj
