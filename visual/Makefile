#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddryha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 20:31:01 by ddryha            #+#    #+#              #
#    Updated: 2018/03/23 20:31:02 by ddryha           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = visual_filler
FLAGS = -Wall -Wextra -Werror -I.includes
VFLAGS = -lmlx -framework OpenGL -framework AppKit
MLX_LIB = /includes/minilibx_macos
LIB = ../libft
SRC := srcs/visual.c
SRC += srcs/ft_draw.c
SRC += srcs/ft_draw_map.c
SRC += srcs/ft_draw_step.c
SRC += srcs/ft_parsing_data.c
SRC += ../srcs/ft_manage_list.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L.$(MLX_LIB) $(VFLAGS) $(LIB)/libftprintf.a

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
