/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:20:36 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/10 16:51:59 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	push_img(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x, y);
}

void	img_loading(t_map *map)
{
	map->img_ground = mlx_xpm_file_to_image(map->mlx, "./sprites/grass.xpm", &map->img_x, &map->img_y);
	if (map->img_ground == NULL)
		exit(0);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./sprites/tree.xpm", &map->img_x, &map->img_y);
	if (map->img_wall == NULL)
		exit(0);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "./sprites/owl.xpm", &map->img_x, &map->img_y);
	if (map->img_ground == NULL)
		exit(0);
	map->img_hunter = mlx_xpm_file_to_image(map->mlx, "./sprites/hunter.xpm", &map->img_x, &map->img_y);
	if (map->img_wall == NULL)
		exit(0);
	map->img_coin = mlx_xpm_file_to_image(map->mlx, "./sprites/wood_stick.xpm", &map->img_x, &map->img_y);
	if (map->img_ground == NULL)
		exit(0);
	map->img_exit_empty = mlx_xpm_file_to_image(map->mlx, "./sprites/exit_empty.xpm", &map->img_x, &map->img_y);
	if (map->img_wall == NULL)
		exit(0);
	map->img_exit_full = mlx_xpm_file_to_image(map->mlx, "./sprites/exit_full.xpm", &map->img_x, &map->img_y);
	if (map->img_ground == NULL)
		exit(0);
}

void	init_img(t_map *map)
{
	int	x;
	int	y;

	img_loading(map);
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->maps[y][x] == '1')
				push_img(map, x * SPRITE, y * SPRITE, map->img_wall);
			if (map->maps[y][x] == '0')
				push_img(map, x * SPRITE, y * SPRITE, map->img_ground);
			if (map->maps[y][x] == 'P')
				push_img(map, x * SPRITE, y * SPRITE, map->img_player);
			if (map->maps[y][x] == 'H')
				push_img(map, x * SPRITE, y * SPRITE, map->img_hunter);
			if (map->maps[y][x] == 'C')
				push_img(map, x * SPRITE, y * SPRITE, map->img_coin);
			if (map->maps[y][x] == 'e')
				push_img(map, x * SPRITE, y * SPRITE, map->img_exit_empty);
			if (map->maps[y][x] == 'E')
				push_img(map, x * SPRITE, y * SPRITE, map->img_exit_full);
			x++;
		}
		y++;
	}
}
