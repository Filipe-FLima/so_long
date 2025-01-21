/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:18:02 by flima             #+#    #+#             */
/*   Updated: 2025/01/21 15:08:08 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	put_player_direction(t_game_data *game, int i, int j, int d)
{
	if (d == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player2, (j - 1) * TILE_SIZE, i * TILE_SIZE);
	else if (d == 4)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player1, (j + 1) * TILE_SIZE, i * TILE_SIZE);
	else if (game->direction == 1 && d == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player1, j * TILE_SIZE, (i - 1) * TILE_SIZE);
	else if (game->direction == 2 && d == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player2, j * TILE_SIZE, (i - 1) * TILE_SIZE);
	else if (game->direction == 1 && d == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player1, j * TILE_SIZE, (i + 1) * TILE_SIZE);
	else if (game->direction == 2 && d == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player2, j * TILE_SIZE, (i + 1) * TILE_SIZE);
}

void	move_up(t_game_data *game, int i, int j)
{
	if (game->map[i - 1][j] == 'C')
		game->collectibles--;
	if (game->exit_col == j && game->exit_row == (i - 1) && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0, 1);
	}
	if (game->map[i - 1][j] == 'G')
	{
		ft_printf("%d\n", game->moves);
		ft_printf("A man's dreams are endless. Try again.\n");
		free_all(game, 0, 1);
	}
	game->map[i][j] = '0';
	game->map[i - 1][j] = 'P';
	game->player_row = i - 1;
	game->player_col = j;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, (i - 1) * TILE_SIZE);
	put_player_direction(game, i, j, 1);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}

void	move_down(t_game_data *game, int i, int j)
{
	if (game->map[i + 1][j] == 'C')
		game->collectibles--;
	if (game->exit_col == j && game->exit_row == (i + 1) && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0, 1);
	}
	if (game->map[i + 1][j] == 'G')
	{
		ft_printf("%d\n", game->moves);
		ft_printf("A man's dreams are endless. Try again.\n");
		free_all(game, 0, 1);
	}
	game->map[i][j] = '0';
	game->map[i + 1][j] = 'P';
	game->player_row = i + 1;
	game->player_col = j;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, (i + 1) * TILE_SIZE);
	put_player_direction(game, i, j, 2);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}

void	move_left(t_game_data *game, int i, int j)
{
	if (game->map[i][j - 1] == 'C')
		game->collectibles--;
	if (game->exit_col == (j - 1) && game->exit_row == i && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0, 1);
	}
	if (game->map[i][j - 1] == 'G')
	{
		ft_printf("%d\n", game->moves);
		ft_printf("A man's dreams are endless. Try again.\n");
		free_all(game, 0, 1);
	}
	game->map[i][j] = '0';
	game->map[i][j - 1] = 'P';
	game->player_row = i;
	game->player_col = j - 1;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, (j - 1) * TILE_SIZE, i * TILE_SIZE);
	put_player_direction(game, i, j, 3);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}

void	move_right(t_game_data *game, int i, int j)
{
	if (game->map[i][j + 1] == 'C')
		game->collectibles--;
	if (game->exit_col == (j + 1) && game->exit_row == i && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0, 1);
	}
	if (game->map[i][j + 1] == 'G')
	{
		ft_printf("%d\n", game->moves);
		ft_printf("A man's dreams are endless. Try again.\n");
		free_all(game, 0, 1);
	}
	game->map[i][j] = '0';
	game->map[i][j + 1] = 'P';
	game->player_row = i;
	game->player_col = j + 1;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * TILE_SIZE, i * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, (j + 1) * TILE_SIZE, i * TILE_SIZE);
	put_player_direction(game, i, j, 4);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}
