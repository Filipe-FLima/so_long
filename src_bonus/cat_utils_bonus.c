/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:32:11 by flima             #+#    #+#             */
/*   Updated: 2025/01/12 20:12:55 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	cat_position(t_game_data *game)
{
	int	i;
	int	j;
	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == 'G')
			{
				game->cat_row = i;
				game->cat_col = j;
			}
			j++;
		}
		i++;
	}
}

void	check_error_img(t_game_data *game)
{
	if (game->textures.cat_img01 == NULL || game->textures.cat_img02 == NULL \
		|| game->textures.cat_img03 == NULL || game->textures.cat_img04 == NULL \
		|| game->textures.cat_img1 == NULL || game->textures.cat_img2 == NULL \
		|| game->textures.cat_img3 == NULL || game->textures.cat_img4 == NULL)
	{
		ft_printf("Error\nCan't get the image\n");
		free_all(game, 1);
	}
	game->current_frame = 0;
	game->cat_direction = 0;
	game->cat_animation = 0;
	game->cat_move = 0;
}
