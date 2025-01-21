/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:55:11 by flima             #+#    #+#             */
/*   Updated: 2025/01/21 15:08:08 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_hook(int keycode, t_game_data *game)
{
	if (keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT)
		move_player(game, keycode);
	else if (keycode == ESC)
		free_all(game, 0, 1);
	return (0);
}

void	move_player(t_game_data *game, int keycode)
{
	int		i;
	int		j;

	i = game->player_row;
	j = game->player_col;
	game->direction = 1;
	if (!game->collectibles)
		mlx_put_image_to_window(game->mlx, game->window, game->textures.exit, \
		game->exit_col * TILE_SIZE, game->exit_row * TILE_SIZE);
	print_moves_win(game);
	if (keycode == UP && game->map[i - 1][j] != '1')
		move_up(game, i, j);
	else if (keycode == DOWN && game->map[i + 1][j] != '1')
		move_down(game, i, j);
	else if (keycode == LEFT && game->map[i][j - 1] != '1')
	{
		game->direction = 2;
		move_left(game, i, j);
	}
	else if (keycode == RIGHT && game->map[i][j + 1] != '1')
	{
		game->direction = 1;
		move_right(game, i, j);
	}
}
