/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:37:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/06 16:49:37 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_in_tab(char **argv, t_map *map)
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

void map_size(char **argv, t_map *map)
{
	char	*tmp;
	int		fd;
	int		i;

	fd = open(argv[1], 0);
	tmp = get_next_line(fd);
	map->x = ft_strlen(tmp);
	i = 1;
	while (tmp)
	{
		tmp = NULL;
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	map->y = i - 1;
	close(fd);
}

void init_map(char **argv, t_map *map)
{
    map_size(argv, map);
	map_in_tab(argv, map);
	check_tab(map);

	int i = 0;
	while (i < map->y)
	{
		printf("%s", map->maps[i]);
		i++;
	}
}