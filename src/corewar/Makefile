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

COR		=	../../corewar

COR_SRC_DIR =	./

COR_OBJ_DIR =	../../cor_obj/

COR_CFILES =	create_champion.c \
				exit.c \
				exec_process.c \
				op_code.c \
				opcode_add.c \
				opcode_aff.c \
				opcode_and.c \
				opcode_fork.c \
				opcode_ld.c \
				opcode_ldi.c \
				opcode_lfork.c \
				opcode_live.c \
				opcode_lld.c \
				opcode_lldi.c \
				opcode_or.c \
				opcode_st.c \
				opcode_sti.c \
				opcode_sub.c \
				opcode_xor.c \
				opcode_zjmp.c \
				params_opcode.c \
				create_vm.c \
				my_memalloc.c \
				champ_rec_info.c \
				check_arg.c \
				check_nbr_champ.c \
				print_params.c \
				cycle_management.c \
				cycle_nb_live.c \
				stop_corewar.c \
				main.c \
				print_vm.c

COR_SOURCES =	$(addprefix $(COR_SRC_DIR), $(COR_CFILES))

COR_OFILES =	$(COR_CFILES:.c=.o)

COR_OBJECTS =	$(addprefix $(COR_OBJ_DIR), $(COR_OFILES))

INC_COR = $(INC_DIR)corewar.h $(INC_DIR)op.h

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	../../inc/

LIBFT = ../../lib/libft_vm/libft.a

all : $(COR_OBJ_DIR) $(COR)

$(COR) : $(COR_OBJECTS) $(LIBFT)
	gcc $(FLAGS) $(COR_OBJECTS) -L ../../lib/libft_vm/ -lft -o $(COR)

$(COR_OBJ_DIR)%.o : $(COR_SRC_DIR)%.c $(INC_COR)
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft_vm/inc/

$(COR_OBJ_DIR) :
	@mkdir -p $(COR_OBJ_DIR)

clean : obj
	@rm -rf $(COR_OBJ_DIR)

fclean : obj
	@rm -f $(COR)
	@rm -rf $(COR_OBJ_DIR)

re :
	@rm -f $(COR)
	@rm -rf $(COR_OBJ_DIR)
	@make

.PHONY: all clean fclean re obj
