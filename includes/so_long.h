/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:43:52 by flima             #+#    #+#             */
/*   Updated: 2025/01/10 21:17:44 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"

# define tile_size 64
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

typedef struct s_textures
{
	void	*player1;
	void	*player2;
	void	*ground;
	void	*colectable;
	void	*exit;
	void	*wall;
}			t_textures;

typedef struct s_game_data
{
	void		*mlx;
	void		*window;
	char		**map;
	int			map_rows;
	int			map_cols;
	int			collectibles;
	int			player_row;
	int			player_col;
	int			exit_row;
	int			exit_col;
	int			moves;
	int			direction;
	t_textures	textures;

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
void	check_valid_path(t_game_data *game, int i, int j);
void	player_exit_position(t_game_data *game);
//free functions
void	free_map(t_game_data *game);
int		free_all(t_game_data *game, int quit);
void	free_visited(int **visited, t_game_data *game);
void	free_texture(t_game_data *game);
//create mao/window
void	get_images(t_game_data *game); //static??
void	create_game_map(t_game_data *game);
void	fill_floor_wall(t_game_data *game);
void	fill_player_exit_colec(t_game_data *game);
//moviments funtions
int		key_hook(int keycode, t_game_data *game);
void	move_player(t_game_data *game, int keycode);
void	move_up(t_game_data *game, int i, int j);
void	move_down(t_game_data *game, int i, int j);
void	move_left(t_game_data *game, int i, int j);
void	move_right(t_game_data *game, int i, int j);

#endif