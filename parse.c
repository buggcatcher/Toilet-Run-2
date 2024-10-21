/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:27:42 by mailinci          #+#    #+#             */
/*   Updated: 2024/10/21 22:12:51 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_usage_and_file_type(int argc, char *map_file)
{
	int	filename_length;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long [map.ber]\n");
		return (1);
	}
	filename_length = ft_strlen(map_file);
	if (filename_length < 4 || \
	ft_strncmp(map_file + filename_length - 4, ".ber", 4))
	{
		ft_printf("Error: Invalid file type\n");
		return (1);
	}
	return (0);
}

static int	validate_file(char *map_file, int *fd)
{
	*fd = open(map_file, O_RDONLY | __O_DIRECTORY);
	if (*fd >= 0)
	{
		close(*fd);
		ft_printf("Error: The map must be a file\n");
		return (1);
	}
	*fd = open(map_file, O_RDONLY);
	if (*fd < 0)
	{
		ft_printf("Error: Unable to open the map file\n");
		return (1);
	}
	return (0);
}

int	check_map_line_lengths(int fd)
{
	char	*line;
	size_t	current_length;
	size_t	line_length;

	line = ft_get_next_line(fd);
	if (!line)
		return (1);
	line_length = ft_strlen(line);
	if (line[line_length - 1] == '\n')
		line_length--;
	while (line != NULL)
	{
		current_length = ft_strlen(line);
		if (line[current_length - 1] == '\n')
			current_length--;
		if (current_length != line_length)
		{
			free (line);
			return (1);
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	return (0);
}

int	check_map_objects(char *map_file)
{
	t_objects	object;

	set_objects(&object);
	object.fd = open(map_file, O_RDONLY);
	object.line = ft_get_next_line(object.fd);
	while (object.line != NULL)
	{
		count_objects_in_line(object.line, &object);
		free(object.line);
		object.line = ft_get_next_line(object.fd);
	}
	close(object.fd);
	if (object.poopie == 1 && object.exit == 1 && object.collectible >= 1)
		return (0);
	else
		return (1);
}

int	validate_map_file(char *map_file)
{
	t_objects	o;

	if (validate_file(map_file, &o.fd))
		exit(1);
	if (check_map_line_lengths(o.fd))
	{
		ft_printf("Error: Invalid map\n");
		close(o.fd);
		exit(1);
	}
	if (check_map_objects(map_file))
	{
		ft_printf("Error: Invalid objects\n");
		close(o.fd);
		exit(1);
	}
	return (0);
}
