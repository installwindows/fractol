# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/06 17:39:37 by varnaud           #+#    #+#              #
#    Updated: 2017/05/06 17:47:54 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c \
	  setup_fractol.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -Ilibft -Imlx
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(OBJ) -Llibft -Lmlx -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ): fractol.h

clean:
	make -C libft clean
	make -C mlx clean
	-rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	-rm -rf $(NAME)

re: fclean all
