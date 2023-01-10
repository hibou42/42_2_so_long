/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/10 16:54:56 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_check(t_map *map)
{
	// a faire
	int	res;

	int	tmp = map->y;
	(void)tmp;
	res = 0;
	return (res);
}

int	x_check(t_map *map)
{
	int	res;
	int	tmp;
	int	i;

	res = 0;
	i = 0;
	while (i < map->y)
	{
		tmp = ft_strlen(map->maps[i]) - 1;
		if (tmp != map->x)
			res = 1;
		i++;
	}
	return (res);
}

int	y_check(t_map *map)
{
	if (map->y < 3)
		return (1);
	return (0);
}

void	check_tab(t_map *map)
{
	int	res;

	res = 0;
	res += y_check(map);
	res += x_check(map);
	res += wall_check(map);
	if (res > 0)
		free_and_exit(map);
}
