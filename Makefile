#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddryha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 17:47:44 by ddryha            #+#    #+#              #
#    Updated: 2018/03/19 17:47:45 by ddryha           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ddryha.filler
FLAGS = -Wall -Wextra -Werror -I.includes
LIB = ./libft
VIS = ./visual
SRC := srcs/filler.c
SRC += srcs/ft_algo.c
SRC += srcs/ft_manage_list.c
SRC += srcs/ft_check_place.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	make -C $(VIS)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB)/libftprintf.a

clean:
	@make clean -C $(LIB)
	@make clean -C $(VIS)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(LIB)
	@make fclean -C $(VIS)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
