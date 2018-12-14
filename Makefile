# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/12/14 17:52:22 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/14 19:12:00 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	./inc/

all : libft asm corewar

libft :
	@make -C ./lib/libft/

asm :
	@make -C ./src/asm/

corewar :
	@make -C ./src/corewar/

clean :
	@make clean -C ./lib/libft/
	@make clean -C ./src/asm/
	@make clean -C ./src/corewar/

fclean :
	@make fclean -C ./lib/libft/
	@make fclean -C ./src/asm/
	@make fclean -C ./src/corewar/

re :
	@make re -C ./lib/libft/
	@make re -C ./src/asm/
	@make re -C ./src/corewar/

install :
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install npm
	brew install soket.io

.PHONY: all clean fclean re libft corewar asm