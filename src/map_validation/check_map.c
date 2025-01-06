/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:57:14 by flima             #+#    #+#             */
/*   Updated: 2025/01/06 19:36:37 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_map_dimensions(t_game_data *game)
{
	int	cols;
	int	rows;
	int	i;

	rows = game->map_rows;
	i = 0;
	while (game->map[i] != NULL)
	{
		cols = 0;
		while (game->map[i][cols] != '\n' && game->map[i][cols])
			cols++;
		if ((cols) != game->map_cols)
		{
			free_map(game);
			print_errors_exit(-5);
		}
		i++;
	}
	if (rows < 3 || rows >= game->map_cols)
	{
		free_map(game);
		print_errors_exit(-5);
	}
}

void	check_map_walls(t_game_data *game, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (game->map[0][i] != '1' || game->map[row -1][i] != '1')
		{
			free_map(game);	
			print_errors_exit(-6);
		}	
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (game->map[i][0] != '1' || game->map[i][col - 1] != '1')
		{
			free_map(game);	
			print_errors_exit(-6);
		}	
		i++;
	}
}
void	verify_valid_characters(t_game_data *game)
{
	int	i;
	int	j;
	char **map;
	i = 0;

	map = game->map;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (map[i][j] != 'P' && map[i][j] != 'C'  && map[i][j] != '1' \
				&& map[i][j] != '0' && map[i][j] != 'E')
			{
				free_map(game);
				print_errors_exit(-8);
			}
			j++;
		}
		i++;
	}
}
static void	verify_characters(t_game_data *game, int E, int P, int O)
{
	if (E != 1 || P != 1)
	{
		free_map(game);
		print_errors_exit(-7);
	}
	if (O < 1 || game->collectibles < 1)
	{
		free_map(game);
		print_errors_exit(-7);
	}
	verify_valid_characters(game);
}

void	check_all_characters(t_game_data *game, int i, int j)
{
	int	nb_exit;
	int	nb_player;
	int	nb_spaces;

	nb_exit = 0;
	nb_player = 0;
	nb_spaces = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == 'P')
				nb_player += 1;
			else if (game->map[i][j] == 'E')
				nb_exit += 1;
			else if (game->map[i][j] == 'C')
				game->collectibles += 1;
			else if (game->map[i][j] == '0')
				nb_spaces += 1;
			j++;
		}
		i++;
	}
	verify_characters(game, nb_exit, nb_player, nb_spaces);
}

