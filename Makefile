# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 20:37:46 by akoropet          #+#    #+#              #
#    Updated: 2019/03/08 14:29:51 by akoropet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = akoropet.filler

NAME_V = visualizator

SRC = main.c figure.c find_coord.c map.c

SRС_V = visualizator.c print.c

LIB = ./lib/lib.a

OB = $(SRC:.c=.o)

OB_V = $(SRС_V:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME) $(NAME_V)

$(NAME): $(OB)
	@make -C lib
	@gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB)
	@echo "\033[94m>>>\033[93mfiller done\033[94m<<<\033[0m"

%.o : %.c
	@gcc $(FLAGS) -c -o  $@ $<

$(NAME_V): $(OB_V)
	@gcc $(FLAGS) $(SRС_V) -o $(NAME_V) $(LIB)
	@echo "\033[96m>>>\033[95mvisual done\033[96m<<<\033[0m"

clean:
	@make clean -C lib
	@rm -f $(OB)
	@rm -f $(OB_V)

fclean: clean
	@make fclean -C lib
	@rm -f $(NAME)
	@rm -f $(NAME_V)

re: fclean all