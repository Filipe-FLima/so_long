/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:32:11 by flima             #+#    #+#             */
/*   Updated: 2025/01/21 15:08:08 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
		|| game->textures.cat_img3 == NULL || game->textures.cat_img4 == NULL \
		|| game->textures.backgr == NULL)
	{
		ft_printf("Error\nCan't get the image\n");
		free_all(game, 1, 1);
	}
	game->current_frame = 0;
	game->cat_direction = 0;
	game->cat_animation = 0;
	game->cat_move = 0;
	game->level = 0;
}

void	game_level(t_game_data *game)
{
	if (game->level < 60)
		usleep(137000);
	else if (game->level < 100)
		usleep(50000);
	else if (game->level < 200)
		usleep(40000);
	else if (game->level < 300)
		usleep(30000);
	else if (game->level < 350)
		usleep(10000);
	else
		usleep(300);
	game->level++;
}

void	print_moves_win(t_game_data *game)
{
	char	*move;
	char	*msg;

	move = ft_itoa(game->moves);
	msg = ft_strjoin("Movements: ", move);
	free(move);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.backgr, 0, 0);
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFFFFFF, msg);
	free(msg);
}