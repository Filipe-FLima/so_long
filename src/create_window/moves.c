/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:18:02 by flima             #+#    #+#             */
/*   Updated: 2025/01/10 20:59:54 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	put_player_direction(t_game_data *game, int i, int j, int d)
{
	if (game->direction == 1 && d == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player1, j * tile_size, (i - 1) * tile_size);
	else if (game->direction == 2 && d == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player2, j * tile_size, (i - 1) * tile_size);
	else if (game->direction == 1 && d == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player1, j * tile_size, (i + 1) * tile_size);
	else if (game->direction == 2 && d == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.player2, j * tile_size, (i + 1) * tile_size);
	
}
void	move_up(t_game_data *game, int i, int j)
{
	if (game->map[i - 1][j] == 'C')
		game->collectibles--;
	if (game->map[i - 1][j] == 'E' && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0);
	}
	else if (game->map[i - 1][j] == 'E')
		return ;
	game->map[i][j] = '0';
	game->map[i - 1][j] = 'P';
	game->player_row = i - 1;
	game->player_col = j;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * tile_size, i * tile_size);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * tile_size, (i - 1) * tile_size);
	put_player_direction(game, i, j, 1);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}

void	move_down(t_game_data *game, int i, int j)
{
	if (game->map[i + 1][j] == 'C')
		game->collectibles--;
	if (game->map[i + 1][j] == 'E' && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0);
	}
	else if (game->map[i + 1][j] == 'E')
		return ;
	game->map[i][j] = '0';
	game->map[i + 1][j] = 'P';
	game->player_row = i + 1;
	game->player_col = j;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * tile_size, i * tile_size);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * tile_size, (i + 1) * tile_size);
	put_player_direction(game, i, j, 2);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}

void	move_left(t_game_data *game, int i, int j)
{
	if (game->map[i][j - 1] == 'C')
		game->collectibles--;
	if (game->map[i][j - 1] == 'E' && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0);
	}
	else if (game->map[i][j - 1] == 'E')
		return ;
	game->map[i][j] = '0';
	game->map[i][j - 1] = 'P';
	game->player_row = i;
	game->player_col = j - 1;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * tile_size, i * tile_size);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, (j - 1) * tile_size, i * tile_size);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.player2, (j - 1) * tile_size, i * tile_size);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}

void	move_right(t_game_data *game, int i, int j)
{
	if (game->map[i][j + 1] == 'C')
		game->collectibles--;
	if (game->map[i][j + 1] == 'E' && !game->collectibles)
	{
		ft_printf("%d\n", game->moves);
		ft_printf("You found the treasure, but wait... Where's Zoro?\n");
		free_all(game, 0);
	}
	else if (game->map[i][j + 1] == 'E')
		return ;
	game->map[i][j] = '0';
	game->map[i][j + 1] = 'P';
	game->player_row = i;
	game->player_col = j + 1;
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, j * tile_size, i * tile_size);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, (j + 1) * tile_size, i * tile_size);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.player1, (j + 1) * tile_size, i * tile_size);
	ft_printf("%i\n", game->moves);
	game->moves += 1;
}
