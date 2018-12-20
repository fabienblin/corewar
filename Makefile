# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/12/14 17:52:22 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/17 16:42:35 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	./inc/

ASM = ./asm

COREWAR = ./corewar

DECOMPILER = ./decompiler

all : libft
	@make -C ./src/asm/
	@make -C ./src/corewar/
	@make -C ./src/decompiler/

libft :
	@make -C ./lib/libft/

$(ASM) :
	@make -C ./src/asm/

$(COREWAR) :
	@make -C ./src/corewar/

$(DECOMPILER) :
	@make -C ./src/decompiler/

clean :
	@make clean -C ./lib/libft/
	@make clean -C ./src/asm/
	@make clean -C ./src/corewar/
	@make clean -C ./src/decompiler/

fclean :
	@make fclean -C ./lib/libft/
	@make fclean -C ./src/asm/
	@make fclean -C ./src/corewar/
	@make fclean -C ./src/decompiler/

re :
	@make re -C ./lib/libft/
	@make re -C ./src/asm/
	@make re -C ./src/corewar/
	@make re -C ./src/decompiler/

debug_asm : libft
	make debug -C ./src/asm/

debug_corewar : libft
	make debug -C ./src/corewar/

debug_decompiler : libft
	make debug -C ./src/decompiler/

install :
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install npm
	brew install soket.io

remove_cor :
	find ./ -type f -name "*.cor" -delete

.PHONY: all clean fclean re libft corewar asm
