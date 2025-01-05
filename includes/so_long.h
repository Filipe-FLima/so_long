/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:43:52 by flima             #+#    #+#             */
/*   Updated: 2025/01/05 17:23:55 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
 #define SO_LONG_H
 
#include "libft.h"

typedef struct s_game_data
{
	char	**map;
	int		map_rows;
	int		map_cols;
	int		collectibles;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	
}			t_game_data;


int		main(int argc, char **argv);
void	print_errors_exit(int error);
//check map functions
void	check_valid_file(char	**argv, t_game_data *game);
void	get_map_data(char	**argv, t_game_data *game, int i);
void	check_map_dimensions(t_game_data *game);
void	check_map_isvalid(t_game_data *game);
void	check_map_walls(t_game_data *game, int row, int col);
void	check_all_characters(t_game_data *game, int i, int j);
void	check_valid_path(t_game_data *game);
void	player_exit_position(t_game_data *game);
//free functions
void	free_map(t_game_data *game);
void	free_visited(int **visited, t_game_data *game);

#endif