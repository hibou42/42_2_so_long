/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/10 16:59:21 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_map *map)
{
	if (key == LEFT_KEY || key == A_KEY)
		{}
	if (key == DOWN_KEY || key == S_KEY)
		{}
	if (key == RIGHT_KEY || key == D_KEY)
		{}
	if (key == LEFT_KEY || key == A_KEY)
		{}
	if (key == ESC)
		close_window(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	check_arg(argc, argv);
	init_map(argv, &map);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, map.x * SPRITE, map.y * SPRITE, "So Long");
	init_img(&map);
	mlx_key_hook(map.mlx_win, deal_key, &map);
	mlx_hook(map.mlx_win, 17, 1L << 0, close_window, &map);
	mlx_loop(map.mlx);
	return (0);
}

/*
Setup if mouse is needed :

mlx_mouse_hook(map.mlx_win, deal_mouse, (void*)0);
int	deal_mouse(int key)
{
	(void) key;
	return (0);
}
*/