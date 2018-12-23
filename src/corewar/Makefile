# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/10/08 18:51:13 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/22 16:35:19 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

COREWAR		=	../../corewar

COREWAR_SRC_DIR =	./

COREWAR_OBJ_DIR =	../../corewar_obj/

# SOURCE DIRECTORIES #

DIR_CREATE_CHAMPION = ./create_champion/

DIR_EXIT = ./exit/

DIR_FUNCTIONS_OPCODE = ./functions_opcode/

DIR_FUNCTIONS_VM = ./functions_vm/

DIR_MY_FREE = ./my_free/

DIR_CONTROL_PARAM_COREWAR = ./control_param_corewar/

DIR_DEBUG_PRINT = ./debug_print/

DIR_FUNCTIONS_CYCLE_MANAGEMENT = ./functions_cycle_management/

DIR_FUNCTIONS_PROCESS_LIVE = ./functions_process_live/

DIR_MAIN = ./

DIR_PRINT = ./print/

# SOURCE FILES #

SRC_CREATE_CHAMPION = \
create_champion.c

SRC_EXIT = \
exit.c

SRC_FUNCTIONS_OPCODE = \
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

SRC_FUNCTIONS_VM = \
create_vm.c

SRC_MY_FREE = \
my_memalloc.c

SRC_CONTROL_PARAM_COREWAR = \
champ_rec_info.c \
check_arg.c \
check_nbr_champ.c

SRC_DEBUG_PRINT = \
print_params.c

SRC_FUNCTIONS_CYCLE_MANAGEMENT = \
cycle_management.c

SRC_FUNCTIONS_PROCESS_LIVE = \
cycle_nb_live.c \
stop_corewar.c

SRC_MAIN = \
main.c

SRC_PRINT = \
print_vm.c

# ALL SOURCES #

COREWAR_CFILES = \
$(SRC_CREATE_CHAMPION) \
$(SRC_EXIT) \
$(SRC_FUNCTIONS_OPCODE) \
$(SRC_FUNCTIONS_VM) \
$(SRC_MY_FREE) \
$(SRC_CONTROL_PARAM_COREWAR) \
$(SRC_DEBUG_PRINT) \
$(SRC_FUNCTIONS_CYCLE_MANAGEMENT) \
$(SRC_FUNCTIONS_PROCESS_LIVE) \
$(SRC_MAIN) \
$(SRC_PRINT)

COREWAR_SOURCES = \
$(addprefix $(DIR_CREATE_CHAMPION), $(SRC_CREATE_CHAMPION)) \
$(addprefix $(DIR_EXIT), $(SRC_EXIT)) \
$(addprefix $(DIR_FUNCTIONS_OPCODE), $(SRC_FUNCTIONS_OPCODE)) \
$(addprefix $(DIR_FUNCTIONS_VM), $(SRC_FUNCTIONS_VM)) \
$(addprefix $(DIR_MY_FREE), $(SRC_MY_FREE)) \
$(addprefix $(DIR_CONTROL_PARAM_COREWAR), $(SRC_CONTROL_PARAM_COREWAR)) \
$(addprefix $(DIR_DEBUG_PRINT), $(SRC_DEBUG_PRINT)) \
$(addprefix $(DIR_FUNCTIONS_CYCLE_MANAGEMENT), $(SRC_FUNCTIONS_CYCLE_MANAGEMENT)) \
$(addprefix $(DIR_FUNCTIONS_PROCESS_LIVE), $(SRC_FUNCTIONS_PROCESS_LIVE)) \
$(addprefix $(DIR_MAIN), $(SRC_MAIN)) \
$(addprefix $(DIR_PRINT), $(SRC_PRINT)) \

COREWAR_OFILES = $(COREWAR_CFILES:.c=.o)

COREWAR_OBJECTS = $(addprefix $(COREWAR_OBJ_DIR), $(COREWAR_OFILES))

FLAGS = -Wall -Wextra -Werror

INC_DIR = ../../inc/

LIBFT = ../../lib/libft/libft.a

all : $(COREWAR_OBJ_DIR) $(COREWAR)

$(COREWAR) : $(COREWAR_OBJECTS) $(LIBFT)
	gcc $(FLAGS) $(COREWAR_OBJECTS) -L ../../lib/libft/ -lft -o $(COREWAR)

$(COREWAR_OBJ_DIR)%.o : $(DIR_CREATE_CHAMPION)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_EXIT)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_FUNCTIONS_OPCODE)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_FUNCTIONS_VM)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_MY_FREE)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_CONTROL_PARAM_COREWAR)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_DEBUG_PRINT)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_FUNCTIONS_CYCLE_MANAGEMENT)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_FUNCTIONS_PROCESS_LIVE)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_MAIN)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR)%.o : $(DIR_PRINT)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COREWAR_OBJ_DIR) :
	@mkdir -p $(COREWAR_OBJ_DIR)

clean : obj
	@rm -rf $(COREWAR_OBJ_DIR)

fclean : obj
	@rm -f $(COREWAR)
	@rm -rf $(COREWAR_OBJ_DIR)

re :
	@rm -f $(COREWAR)
	@rm -rf $(COREWAR_OBJ_DIR)
	@make

debug :
	gcc -ggdb $(COREWAR_SOURCES) ../../lib/libft/libft.a -I ../../lib/libft/inc -I $(INC_DIR) -o corewar_debug
	lldb ./corewar_debug ../../test.cor

.PHONY: all clean fclean re obj
