/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:30:42 by flima             #+#    #+#             */
/*   Updated: 2025/01/13 17:41:21 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

int	free_all(t_game_data *game, int quit, int init)

{
	free_texture(game, init);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	if (quit == 1)
		exit(1);
	else
		exit(0);
	return (0);
}

static void	free_cat_texture(t_game_data *game, int init)
{
	if (init == 1)
	{
		if (game->textures.cat_img1 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img1);
		if (game->textures.cat_img2 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img2);
		if (game->textures.cat_img3 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img3);
		if (game->textures.cat_img4 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img4);
		if (game->textures.cat_img01 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img01);
		if (game->textures.cat_img02 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img02);
		if (game->textures.cat_img03 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img03);
		if (game->textures.cat_img04 != NULL)
			mlx_destroy_image(game->mlx, game->textures.cat_img04);
		if (game->textures.backgr != NULL)
			mlx_destroy_image(game->mlx, game->textures.backgr);
	}
}

void	free_texture(t_game_data *game, int init)
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
	free_cat_texture(game, init);
}
