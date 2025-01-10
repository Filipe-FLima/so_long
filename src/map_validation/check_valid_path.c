/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:24:35 by flima             #+#    #+#             */
/*   Updated: 2025/01/10 17:21:26 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	visited_path(t_game_data *game, int row, int col, int **visited)
{
	if (game->map[row][col] == '1' || visited[row][col])
		return ;
	if (game->map[row][col] == 'E')
		visited[row][col] = 1;
	else
	{
		visited[row][col] = 1;
		visited_path(game, row + 1, col, visited);
		visited_path(game, row - 1, col, visited);
		visited_path(game, row, col + 1, visited);
		visited_path(game, row, col - 1, visited);
	}
}
static int	**get_visited(t_game_data *game)
{
	int	**visited;
	int	i;

	visited = (int **)ft_calloc(game->map_rows, sizeof(int *));
	if (!visited)
	{
		free_map(game);
		print_errors_exit(-4);
	}
	i = 0;
	while (i < game->map_rows)
	{
		visited[i] = (int *)ft_calloc(game->map_cols, sizeof(int));
		if (!visited[i])
		{
			free_map(game);
			print_errors_exit(-4);
		}
		i++;
	}
	return (visited);
}

void	check_valid_path(t_game_data *game, int i, int j)
{
	int	**visited;

	player_exit_position(game);
	visited = get_visited(game);
	visited_path(game, game->player_row, game->player_col, visited);
	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if ((game->map[i][j] == 'C' && !visited[i][j]) \
				|| (game->map[i][j] == 'E' && !visited[i][j]))
			{
				free_visited(visited, game);
				free_map(game);
				print_errors_exit(-9);
			}
			j++;
		}
		i++;
	}
	free_visited(visited, game);
}

void	player_exit_position(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_row = i;
				game->player_col = j;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_row = i;
				game->exit_col = j;
			}
			j++;
		}
		i++;
	}
}
