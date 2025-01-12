/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:15:42 by flima             #+#    #+#             */
/*   Updated: 2025/01/12 20:47:22 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"


static void cat_move_right(t_game_data *game, int i, int j)
{
	if (game->map[i][j + 1] == '1' || \
		game->map[i][j + 1] == 'C' || \
		game->map[i][j + 1] == 'E')
		return ;
	if (game->map[i][j + 1] == 'P')
	{
		ft_printf("A man's dreams are endless. Try again\n");
		free_all(game, 0);
	}
	game->map[i][j] = '0';
	game->map[i][j + 1] = 'G';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	if (game->cat_direction == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img1, (j + 1) * TILE_SIZE, i * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img01, (j + 1) * TILE_SIZE, i * TILE_SIZE);
}
static void cat_move_left(t_game_data *game, int i, int j)
{
	if (game->map[i][j - 1] == '1' || \
		game->map[i][j - 1] == 'C' || \
		game->map[i][j - 1] == 'E')
		return ;
	if (game->map[i][j - 1] == 'P')
	{
		ft_printf("A man's dreams are endless. Try again\n");
		free_all(game, 0);
	}
	game->map[i][j] = '0';
	game->map[i][j - 1] = 'G';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	if (game->cat_direction == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img1, (j - 1) * TILE_SIZE, i * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img01, (j - 1) * TILE_SIZE, i * TILE_SIZE);
}

static void cat_move_up(t_game_data *game, int i, int j)
{
	if (game->map[i - 1][j] == '1' || \
		game->map[i - 1][j] == 'C' || \
		game->map[i - 1][j] == 'E')
		return ;
	if (game->map[i - 1][j] == 'P')
	{
		ft_printf("A man's dreams are endless. Try again\n");
		free_all(game, 0);
	}
	game->map[i][j] = '0';
	game->map[i - 1][j] = 'G';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	if (game->cat_direction == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img1, j * TILE_SIZE, (i - 1) * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img01, j * TILE_SIZE, (i - 1) * TILE_SIZE);
}
static void cat_move_down(t_game_data *game, int i, int j)
{
	if (game->map[i + 1][j] == '1' || \
		game->map[i + 1][j] == 'C' || \
		game->map[i + 1][j] == 'E')
		return ;
	if (game->map[i + 1][j] == 'P')
	{
		ft_printf("A man's dreams are endless. Try again\n");
		free_all(game, 0);
	}
	game->map[i][j] = '0';
	game->map[i + 1][j] = 'G';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	if (game->cat_direction == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img1, j * TILE_SIZE, (i + 1) * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.cat_img01, j * TILE_SIZE, (i + 1) * TILE_SIZE);
}

void	cat_move(t_game_data *game)
{
	int	random;
	int	i;
	int	j;
	
	cat_position(game);
	i = game->cat_row;
	j = game->cat_col;
	random = rand() % 4;
	
	if (random == CATUP)
		cat_move_up(game, i, j);
	else if (random == CATRIGHT)
	{
		game->cat_direction = 0;
		cat_move_right(game, i, j);
	}
	else if (random == CATLEFT)
	{
		game->cat_direction = 1;
		cat_move_left(game, i, j);
	}
	else if (random == CATDOWN)
		cat_move_down(game, i, j);
}

