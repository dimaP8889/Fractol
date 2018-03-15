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
SRC = fractol.c ft_jul_fract.c ft_men_fract.c ft_catch_key.c ft_mouse_zoom.c
HEADER = fractol.h
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -lmlx
MLX = minilibx/
CC = gcc
FLAG_FRAME = -framework
FRAMEWORK = $(FLAG_FRAME) OpenGL $(FLAG_FRAME) AppKit
MULT = -lpthread

comp:
	$(CC) $(FLAGS) -o $(NAME) $(MULT) $(SRC) $(LIBA) -L $(MLX) $(FLAGS_MLX) $(FRAMEWORK)
