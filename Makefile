# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/06 17:39:37 by varnaud           #+#    #+#              #
#    Updated: 2017/05/08 02:40:20 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c \
	  setup_fractol.c \
	  hook.c \
	  key.c \
	  draw.c \
	  fractals.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Tk.framework/Versions/8.4/Headers -Ilibft -Imlx 
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(OBJ) -Llibft -Lmlx -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME) 

linux: $(OBJ)
	make -C libft 
	gcc $(OBJ) -Llibft -lft -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJ): fractol.h keys.h

clean:
	make -C libft clean
	make -C mlx clean
	-rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	-rm -rf $(NAME)

re: fclean all
