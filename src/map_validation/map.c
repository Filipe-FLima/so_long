/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:06:08 by flima             #+#    #+#             */
/*   Updated: 2025/01/09 20:47:56 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_valid_file(char	**argv, t_game_data *game)
{
	int		fd;
	char	*line;
	int		i;

	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		print_errors_exit(-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_errors_exit(-2);
	line = get_next_line(fd);
	if (line == NULL)
		print_errors_exit(-3);
	i = 0;
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	get_map_data(argv, game, i);
}

void	get_map_data(char	**argv, t_game_data *game, int rows)
{
	int	i;
	int	cols;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	game->map = malloc(sizeof(char *) * (rows + 1));
	if (game->map == NULL)
		print_errors_exit(-4);
	i = 0;
	while (i < (rows + 1))
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	cols = 0;
	while (game->map[0][cols] != '\n' && game->map[0][cols])
		cols++;
	game->map_rows = rows;
	game->map_cols = cols;
	check_map_isvalid(game);
}

void	check_map_isvalid(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->collectibles = 0;
	game->moves = 1;
	check_map_dimensions(game);
	check_map_walls(game, game->map_rows, game->map_cols);
	check_all_characters(game, i, j);
	check_valid_path(game, i, j);
}
