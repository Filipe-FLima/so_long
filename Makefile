# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 19:00:22 by flima             #+#    #+#              #
#    Updated: 2025/01/09 21:00:10 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES_DIR = includes
CFLAGS = -Wall -Wextra -g
CC = cc
LIBFT = Libft/libft.a
MLX = mlx/libmlx.a
OBJS_DIR = objs/
MLX_FLAGS = -I$(INCLUDES_DIR) -L./mlx -lmlx -lX11 -lXext -lm

SRCS = src/map_validation/check_map.c src/map_validation/check_valid_path.c \
		src/map_validation/map.c src/free.c src/main.c \
		src/create_window/create_game_map.c src/create_window/moves.c \
		src/create_window/controllers.c
		
OBJ_O = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_O))

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "ALL DONE!"
	
$(LIBFT):
	@$(MAKE) -C Libft

$(MLX):
	@if [ ! -d "mlx" ]; then \
    @git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@$(MAKE) -C mlx

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)src
	@mkdir -p $(OBJS_DIR)src/map_validation
	@mkdir -p $(OBJS_DIR)src/create_window
	@$(CC) $(CFLAGS) -c $< -o $@ $(MLX_FLAGS)

rmmlx:
	@rm -rf mlx
clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C Libft

fclean: clean
	@$(MAKE) clean -C mlx
	@$(MAKE) fclean -C Libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

