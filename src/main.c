/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:14 by flima             #+#    #+#             */
/*   Updated: 2025/01/06 19:53:30 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_errors_exit(int error)
{
	if (error == -1)
		ft_putstr_fd("Error: Invalid file extension or input.\n", 2);
	if (error == -2)
		ft_putstr_fd("Error: Can't read the map.\n", 2);
	if (error == -3)
		ft_putstr_fd("Error: Empty file / map does not exist.\n", 2);
	if (error == -4)
		ft_putstr_fd("Error: Memory allocation failed using malloc.\n", 2);
	if (error == -5)
		ft_putstr_fd("Error: Invalid map's dimensions.\n", 2);
	if (error == -6)
		ft_putstr_fd("Error: The map is not surrounded by walls\n", 2);
	if (error == -7)
		ft_putstr_fd("Error: The map has an invalid number of required characters.\n", 2);
	if (error == -8)
		ft_putstr_fd("Error: Map contains invalid characters\n", 2);
	// if (error == -8)
	// 	ft_putstr_fd("erroror\nInvalid map\n", 2);
	// if (error == -20)
	// 	ft_putstr_fd("Error\nMap to big to fit in the screen.\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game_data game;
	if (argc == 2)
	{
		check_valid_file(argv, &game);
		// create_game_map(&game);
		free_map(&game);
	}
	else
	{
		ft_putstr_fd("ERROR: Program does not accept more or less than 1 argument\n", 2);
		exit(1);
	}
	ft_printf("all done"); // for test
	return (0);
}