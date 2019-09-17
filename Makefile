# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 17:26:29 by akoropet          #+#    #+#              #
#    Updated: 2019/09/17 18:40:30 by akoropet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			filler
NAME_V = 		visualizator

SRC_DIR = 		./source/
OBJ_DIR = 		./objective/
INC_DIR = 		./include/

SRC =			main.c \
				figure.c \
				find_coord.c \
				map.c

SRC_V = 		visualizator.c \
				print.c

OBJ =           $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
	
OBJ_V = 		$(addprefix $(OBJ_DIR), $(SRC_V:.c=.o))

LIB = 			./lib/lib.a

FLAGS = 		-Wall -Werror -Wextra

all: $(NAME) $(NAME_V)

$(NAME): $(OBJ)
	@make -C lib
	@gcc $(FLAGS) $(addprefix $(SRC_DIR), $(SRC)) $(LIB) -o $(NAME)
	@echo "\033[92m>>>filler compiled<<<\033[0m"

$(NAME_V): $(OBJ_V)
	@make -C lib
	@gcc $(FLAGS) $(addprefix $(SRC_DIR), $(SRC_V)) $(LIB) -o $(NAME_V)
	@echo "\033[92m>>>visualizator compiled<<<\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ): | $(OBJ_DIR)

$(OBJ_V): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@make clean -C lib
	@rm -f $(OBJ)
	@rm -f $(OBJ_V)

fclean: clean
	@make fclean -C lib
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -f $(NAME_V)

re: fclean all

vpath %.c $(SRC_DIR)
