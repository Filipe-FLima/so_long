/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:27:37 by flima             #+#    #+#             */
/*   Updated: 2025/01/21 15:08:08 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	create_game_map(t_game_data *game)
{
	int	width;
	int	height;

	width = game->map_cols * TILE_SIZE;
	height = game->map_rows * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game);
		print_errors_exit(-10);
	}
	game->window = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->window == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game);
		print_errors_exit(-10);
	}
	get_images(game);
	fill_floor_wall(game);
}

void	get_images(t_game_data *game)
{
	int	widght;
	int	height;

	widght = TILE_SIZE;
	height = TILE_SIZE;
	game->textures.player1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_right.xpm", &widght, &height);
	game->textures.player2 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_left.xpm", &widght, &height);
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
	"assets/ground.xpm", &widght, &height);
	game->textures.colectable = mlx_xpm_file_to_image(game->mlx, \
	"assets/colectable.xpm", &widght, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, \
	"assets/exit.xpm", &widght, &height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"assets/wall.xpm", &widght, &height);
	if (game->textures.player1 == NULL || game->textures.ground == NULL \
		|| game->textures.colectable == NULL || game->textures.exit == NULL \
		|| game->textures.wall == NULL || game->textures.player2 == NULL)
	{
		ft_printf("Error\nCan't get the image\n");
		free_all(game, 1, 0);
	}
	get_cat_textures(game);
}

void	fill_floor_wall(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	add_cat(game);
	fill_player_exit_colec(game);
}

void	fill_player_exit_colec(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.colectable, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.player1, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
