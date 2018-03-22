# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 12:44:02 by dmitriy1          #+#    #+#              #
#    Updated: 2018/03/12 12:52:59 by dmitriy1         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./fractol
LIBA = libft/libft.a
SRC = fractol.c ft_jul_fract.c ft_men_fract.c ft_catch_key.c ft_mouse_zoom.c \
ft_make_col.c ft_make_grad.c ft_mouse_motion.c ft_zoooooom.c ft_keycode_extra.c\
ft_print.c ft_sets_men.c ft_sets_jul.c ft_extra_f.c ft_make_coord.c \
ft_set_start.c 
HEADER = fractol.h
FL = -Wall -Wextra -Werror
F_M = -lmlx
MLX = /usr/local/lib/
CC = gcc
FLAG_FRAME = -framework
FW = $(FLAG_FRAME) OpenGL $(FLAG_FRAME) AppKit
M_H = /usr/local/include
ML = -lpthread

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft
	@$(CC) $(FL) -I $(M_H) -o $(NAME) $(ML) $(SRC) $(LIBA) -L $(MLX) $(F_M) $(FW)

clean:
	@$(MAKE) -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all
