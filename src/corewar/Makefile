# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/10/08 18:51:13 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/15 15:59:20 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

COREWAR =	../../corewar

COR_SRC_DIR =	./

COR_OBJ_DIR =	../../cor_obj/

COR_CFILES =	main.c exit.c

COR_SOURCES =	$(addprefix $(COR_SRC_DIR), $(COR_CFILES))

COR_OFILES =	$(COR_CFILES:.c=.o)

COR_OBJECTS =	$(addprefix $(COR_OBJ_DIR), $(COR_OFILES))

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	../../inc/

LIBFT = ../../lib/libft/libft.a

all : $(COR_OBJ_DIR) $(COREWAR)

$(COREWAR) : $(COR_OBJECTS) $(LIBFT)
	gcc $(FLAGS) $(COR_OBJECTS) -L ../../lib/libft/ -lft -o $(COREWAR)

$(COR_OBJ_DIR)%.o : $(COR_SRC_DIR)%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ../../lib/libft/inc/

$(COR_OBJ_DIR) :
	@mkdir -p $(COR_OBJ_DIR)

clean : obj
	@rm -rf $(COR_OBJ_DIR)

fclean : obj
	@rm -f $(COREWAR)
	@rm -rf $(COR_OBJ_DIR)

re :
	@rm -f $(COREWAR)
	@rm -rf $(COR_OBJ_DIR)
	@make

.PHONY: all clean fclean re obj
