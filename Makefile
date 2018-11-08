# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/10/08 18:51:13 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/10/11 19:07:00 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

SRC_DIR =	./src/corewar/

OBJ_DIR =	./obj/

INC_DIR =	./inc/

NAME =		corewar

CFILES =	main.c exit.c

SOURCES =	$(addprefix $(SRC_DIR), $(CFILES))

OFILES =	$(CFILES:.c=.o) $(FT_PRINTF:.c=.o)

OBJECTS =	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : obj $(OBJECTS)
	@make -C ./lib/libft
	gcc $(FLAGS) $(OBJECTS) -L ./lib/libft/ -lft -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ./lib/libft/inc/

obj :
	@mkdir -p $(OBJ_DIR)

clean : obj
	@make clean -C ./lib/libft/
	@rm -rf $(OBJ_DIR)

fclean : obj
	@make fclean -C ./lib/libft/
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

re : fclean all

install :
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install npm
	brew install soket.io

test :
	@make -C ./lib/libft
	gcc $(SOURCES) -L ./lib/libft/ -lft -o test_corewar -I $(INC_DIR) -I ./lib/libft/inc/

.PHONY: all clean fclean re obj
