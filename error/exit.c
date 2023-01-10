/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:56:40 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/10 16:51:16 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_and_exit(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->y)
	{
		free(map->maps[i]);
		i++;
	}
	free(map->maps);
	ft_printf("free and exit\n");
	exit(0);
}

int	close_window(t_map *map)
{
	if (map->maps)
		free_and_exit(map);
	ft_printf("exit windows\n");
	exit(0);
}
