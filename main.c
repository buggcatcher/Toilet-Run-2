/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:36:45 by mailinci          #+#    #+#             */
/*   Updated: 2024/10/18 14:35:56 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(int argc, char *argv[])
{
	if (check_usage_and_file_type(argc, argv[1]))
		return (1);
	if (validate_map_file(argv[1]))
		return (1);
	if (!is_playable(argv[1]))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	game;

	if (parse(argc, argv))
		return (1);
	game = game_init(argv[1]);
	if (game_start(game))
		return (1);
	return (0);
}
