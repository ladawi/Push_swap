# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 10:40:04 by ladawi            #+#    #+#              #
#    Updated: 2021/12/17 22:37:09 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_LIST=\
	main.c\
	get_list.c\
	check.c\
	swap.c\
	rotate.c\
	push.c\
	rev_rotate.c\
	sort.c\
	exec_stack.c\
	find_nb.c\
	utils.c\
	selec_sort.c\
	try_quicksort.c\
	big_sort_utils.c\
	big_sort_simu_func.c\
	big_sort.c\

SRCO = $(addprefix $(OBJ_DIR)/, $(SRC_LIST:%.c= %.o))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_LIST))

LIBFT_O = $(LIBFT_SRC:%.c= %.o)

LIBFT = ./libft/libft.a

LIBFT_INCLUDE = ./libft/includes/libft.h\
	./libft/includes/get_next_line.h

INCLUDE = includes/Push_swap.h

SRC_DIR = srcs

OBJ_DIR = objs

# FLAGS = -Wall -Werror -Wextra 
# FLAGS = -g3 -fsanitize=address

END = \033[0m
RED = \033[0;91m
YEL = \033[93m
GRE = \033[0;92m
PUR = \033[0;95m
BLU = \033[0;34m
BOLD = \033[1m


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_BONUS_DIR) $(SRCO) $(SRCO_BONUS) $(INCLUDE) $(LIBFT) $(MINILIBX)
	@echo "$(YEL)Made $(NAME)$(END)"
	@echo "$(PUR)Compiling$(END)"
	@gcc $(FLAGS) -o $(NAME) $(SRCO) $(SRCO_BONUS) $(LIBFT) -I libft/includes

$(LIBFT) : $(LIBFT_INCLUDE)
	@make -C ./libft/

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -g -c $< -I includes -I libft/includes -o $@
	@echo "$(GRE)$@$(END)"

clean:
	@make clean -C libft
	@echo "$(RED)$(BOLD)Made [clean] in libft$(END)"
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@echo "$(RED)$(BOLD)Removed *.o $(END)"

re: fclean all

fclean: clean
	@make fclean -C libft
	@echo "$(RED)$(BOLD)Made [fclean] in libft  & minilibx$(END)"
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"

.PHONY : all clean fclean re