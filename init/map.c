/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:37:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/10 16:53:52 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_data_struct(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->maps[y][x] == 'P')
			{
				map->pos_x = x;
				map->pos_y = y;
			}
			if (map->maps[y][x] == 'E')
			{
				map->exit_x = x;
				map->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	map_in_tab(char **argv, t_map *map)
{
	int		fd;
	int		i;

	map->maps = ft_calloc(map->y, sizeof(char *));
	fd = open(argv[1], 0);
	i = 0;
	while (i < map->y)
	{
		map->maps[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	map_size(char **argv, t_map *map)
{
	char	*tmp;
	int		fd;
	int		i;

	fd = open(argv[1], 0);
	tmp = get_next_line(fd);
	map->x = ft_strlen(tmp) - 1;
	i = 1;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	map->y = i - 1;
	close(fd);
}

void	init_map(char **argv, t_map *map)
{
	map_size(argv, map);
	map_in_tab(argv, map);
	check_tab(map);
	add_data_struct(map);
}
