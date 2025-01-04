/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:24:35 by flima             #+#    #+#             */
/*   Updated: 2025/01/04 21:37:50 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_valid_path(t_game_data *game)
{
	char	**mirror_map;
	int		i;

	mirror_map = ft_calloc(game->map_rows, sizeof(int *));
	if (mirror_map == NULL)
	{
		free_map(game);
		print_errors_exit(-4);
	}
	while (i < game->map_rows)
	{
		mirror_map[i] = ft_calloc(game->map_cols, sizeof(int));
		if (mirror_map == NULL)
		{
			free(mirror_map);
			free_map(game);
			print_errors_exit(-4);
		}
		i++;
	}
	
	
}
