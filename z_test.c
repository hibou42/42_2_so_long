/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/04 11:12:06 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	deal_mouse(int key, void *param)
{
	ft_printf("mouse no = %d\n", key);
	param = 0;
	return (0);
}

int	deal_key(int key, void *param)
{
	ft_printf("key no = %d\n", key);
	if (key == 53)
		close_window((void*)0);
	param = 0;
	return (0);
}

int main (int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	check_arg(argc, argv);
	check_map(argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_key_hook(mlx_win, deal_key, (void*)0);
	mlx_mouse_hook(mlx_win, deal_mouse, (void*)0);
	mlx_hook(mlx_win, 17, 0, close_window, 0);	
	mlx_loop(mlx);
	return (0);
}
