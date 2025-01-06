# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 19:00:22 by flima             #+#    #+#              #
#    Updated: 2025/01/06 19:53:49 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES_DIR = /home/flima/ft-projects/so_long/includes
CFLAGS = -Wall -Wextra -g -I$(INCLUDES_DIR)
CC = cc
LIBFT = Libft/libft.a
MLX = mlx/libmlx.a
OBJS_DIR = objs/
MLX_FLAGS = -I$(INCLUDES_DIR) -L./mlx -lmlx -lX11 -lXext -lm

SRCS = src/map_validation/check_map.c src/map_validation/check_valid_path.c \
		src/map_validation/map.c src/free.c src/main.c
		
OBJ_E = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_E))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	
$(LIBFT):
	@$(MAKE) -C Libft

$(MLX):
	@$(MAKE) -C mlx

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(MLX_FLAGS)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C Libft

fclean:
	@$(MAKE) clean -C mlx
	@$(MAKE) fclean -C Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

