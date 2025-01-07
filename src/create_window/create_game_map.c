/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:27:37 by flima             #+#    #+#             */
/*   Updated: 2025/01/07 21:25:53 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	create_game_map(t_game_data *game)
{
	int	width;
	int	height;
	int	i;
	int j;

	i = 0;
	j = 0;
	width = game->map_cols * tile_size;
	height = game->map_rows * tile_size;	
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game);
		print_errors_exit(-10);
	}
	game->window = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->window == NULL)
	{	
		ft_printf("erro to get window\n"); //test
		exit (1);
	}	
	get_images(game);
	fill_map(game, i, j);
}

void	get_images(t_game_data *game)
{
	int widght;
	int	height;

	widght = tile_size;
	height = tile_size;
	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
	"assets/luffy.xpm", &widght, &height);
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
	"assets/ground.xpm", &widght, &height);
	game->textures.colectable = mlx_xpm_file_to_image(game->mlx, \
	"assets/food.xpm", &widght, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, \
	"assets/merry.xpm", &widght, &height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"assets/water.xpm", &widght, &height);
	if (game->textures.player == NULL || game->textures.ground == NULL \
		|| game->textures.colectable == NULL || game->textures.exit == NULL \
		|| game->textures.wall == NULL)
	{
		//free mlx e mapa
		ft_printf("erro open imagens\n"); //test
		exit(1);
	}
}

void	fill_map(t_game_data *game, int i, int j)
{
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.wall, j * tile_size, i * tile_size);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.ground, j * tile_size, i * tile_size);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.exit, j * tile_size, i * tile_size);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.colectable, j * tile_size, i * tile_size);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->textures.player, j * tile_size, i * tile_size);
			j++;
		}
		i++;
	}
}
