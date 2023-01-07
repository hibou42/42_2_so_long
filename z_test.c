/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/07 20:07:09 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_mouse(int key)
{
	ft_printf("mouse no = %d\n", key);
	return (0);
}

int	deal_key(int key)
{
	ft_printf("key no = %d\n", key);
	if (key == 53)
		close_window((void*)0);
	return (0);
}

int main (int argc, char **argv)
{
	t_map	map;
	
	check_arg(argc, argv);
	init_map(argv, &map);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(&map.mlx, map.x * 64, map.y * 64, "So Long");
	init_img(&map);
	
	printf("try BRUT FORCE\n");
	map.img_x = 0;
	map.img_y = 0;
	map.img_wall = mlx_xpm_file_to_image(map.mlx, "./sprites/wall1.xpm", &map.img_x, &map.img_y);
	mlx_put_image_to_window(map.mlx, map.mlx_win, map.img_wall, 0, 0);
	
	mlx_key_hook(map.mlx_win, deal_key, (void*)0);
	mlx_mouse_hook(map.mlx_win, deal_mouse, (void*)0);
	mlx_hook(map.mlx_win, 17, 0, close_window, 0);
	mlx_loop(map.mlx);
	return (0);
}