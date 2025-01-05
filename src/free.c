/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:30:42 by flima             #+#    #+#             */
/*   Updated: 2025/01/05 17:23:42 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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