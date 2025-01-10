/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:30:42 by flima             #+#    #+#             */
/*   Updated: 2025/01/10 21:18:47 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_map(t_game_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_visited(int **visited, t_game_data *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
int	free_all(t_game_data *game, int quit)
{
	free_texture(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	if (quit == 1)
		exit(0);
	else
		exit(0);
	return (0);
}

void	free_texture(t_game_data *game)
{
	if (game->textures.player1 != NULL)
		mlx_destroy_image(game->mlx, game->textures.player1);
	if (game->textures.player2 != NULL)
		mlx_destroy_image(game->mlx, game->textures.player2);
	if (game->textures.ground != NULL)
		mlx_destroy_image(game->mlx, game->textures.ground);
	if (game->textures.colectable != NULL)
		mlx_destroy_image(game->mlx, game->textures.colectable);
	if (game->textures.exit != NULL)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.wall != NULL)
		mlx_destroy_image(game->mlx, game->textures.wall);
}
