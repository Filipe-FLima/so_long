/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:29:15 by flima             #+#    #+#             */
/*   Updated: 2025/01/17 15:57:33 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_cat_textures(t_game_data *game)
{
	int	widght;
	int	height;

	widght = TILE_SIZE;
	height = TILE_SIZE;
	game->textures.cat_img1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat1.xpm", &widght, &height);
	game->textures.cat_img2 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat2.xpm", &widght, &height);
	game->textures.cat_img3 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat3.xpm", &widght, &height);
	game->textures.cat_img4 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat4.xpm", &widght, &height);
	game->textures.cat_img01 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat01.xpm", &widght, &height);
	game->textures.cat_img02 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat02.xpm", &widght, &height);
	game->textures.cat_img03 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat03.xpm", &widght, &height);
	game->textures.cat_img04 = mlx_xpm_file_to_image(game->mlx, \
	"assets/cat04.xpm", &widght, &height);
	game->textures.backgr = mlx_xpm_file_to_image(game->mlx, \
	"assets/moves_backg.xpm", &widght, &height);
	check_error_img(game);
}

void	add_cat(t_game_data *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map_rows && count >= 0)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == '0')
			{
				count++;
				if (count == (game->space / 2) + 1)
				{
					game->map[i][j] = 'G';
					count = -1;
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

static void	cat_animation2(t_game_data *game, int i, int j)
{
	if (game->current_frame == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img01, j * TILE_SIZE, i * TILE_SIZE);
	if (game->current_frame == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img02, j * TILE_SIZE, i * TILE_SIZE);
	if (game->current_frame == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img03, j * TILE_SIZE, i * TILE_SIZE);
	if (game->current_frame == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img04, j * TILE_SIZE, i * TILE_SIZE);
}

static void	cat_animation(t_game_data *game, int i, int j)
{
	if (game->cat_direction == 0)
	{
		if (game->current_frame == 1)
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.cat_img1, j * TILE_SIZE, i * TILE_SIZE);
		if (game->current_frame == 2)
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.cat_img2, j * TILE_SIZE, i * TILE_SIZE);
		if (game->current_frame == 3)
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.cat_img3, j * TILE_SIZE, i * TILE_SIZE);
		if (game->current_frame == 0)
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.cat_img4, j * TILE_SIZE, i * TILE_SIZE);
	}
	else
		cat_animation2(game, i, j);
}

int	cat_frames(void *param)
{
	int			i;
	int			j;
	t_game_data	*game;

	game = (t_game_data *)param;
	cat_position(game);
	i = game->cat_row;
	j = game->cat_col;
	game->cat_animation++;
	if (game->cat_animation >= 1)
	{
		game->current_frame = (game->current_frame + 1) % 4;
		cat_animation(game, i, j);
		game->cat_animation = 0;
	}
	game->cat_move++;
	if (game->cat_move >= 5)
	{
		cat_move(game);
		game->cat_move = 0;
	}
	game_level(game);
	return (0);
}
