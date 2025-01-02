# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 19:00:22 by flima             #+#    #+#              #
#    Updated: 2025/01/02 20:16:02 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g
CC = cc
SRC = 
OBJS = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
MLX_FLAGS = -Imlx -L./mlx -lmlx //MAIS CMANDOS
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)