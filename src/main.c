/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:14 by flima             #+#    #+#             */
/*   Updated: 2025/01/10 19:42:53 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_errors_exit(int error)
{
	if (error == -1)
		ft_putstr_fd("Error\nInvalid file extension or input.\n", 2);
	if (error == -2)
		ft_putstr_fd("Error\nCan't read the map.\n", 2);
	if (error == -3)
		ft_putstr_fd("Error\nEmpty file / map does not exist.\n", 2);
	if (error == -4)
		ft_putstr_fd("Error\nMemory allocation failed using malloc.\n", 2);
	if (error == -5)
		ft_putstr_fd("Error\nInvalid map's dimensions.\n", 2);
	if (error == -6)
		ft_putstr_fd("Error\nThe map is not surrounded by walls\n", 2);
	if (error == -7)
		ft_putstr_fd("Error\nInvalid number of required characters.\n", 2);
	if (error == -8)
		ft_putstr_fd("Error\nMap contains invalid characters\n", 2);
	if (error == -9)
		ft_putstr_fd("Error\nInvalid path\n", 2);
	if (error == -10)
		ft_putstr_fd("Error\nCan not create the game window.\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game_data	game;

	if (argc == 2)
	{
		check_valid_file(argv, &game);
		create_game_map(&game);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_hook(game.window, 17, 0, free_all, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		ft_putstr_fd("ERROR: No more or less than 1 argument\n", 2);
		exit(1);
	}
	ft_printf("all done"); // for test
	return (0);
}
