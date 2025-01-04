/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:43:52 by flima             #+#    #+#             */
/*   Updated: 2025/01/04 21:22:08 by flima            ###   ########.fr       */
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
	int		exit_row;
	
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
//free functions
void	free_map(t_game_data *game);

#endif