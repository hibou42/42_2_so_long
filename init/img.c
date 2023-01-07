/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:20:36 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/07 20:03:59 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void push_img(t_map *map, int x, int y, void *img)
{
    printf("push img x = %d push img y = %d\n", x, y);
    mlx_put_image_to_window(map->mlx, map->mlx_win, img, x, y);
}

void img_loading(t_map *map)
{
    map->img_ground = mlx_xpm_file_to_image(map->mlx, "./sprites/ground1.xpm", &map->img_x, &map->img_y);
    if (map->img_ground == NULL)
        exit(0);
    map->img_wall =  mlx_xpm_file_to_image(map->mlx, "./sprites/wall1.xpm", &map->img_x, &map->img_y);
    if (map->img_wall == NULL)
        exit(0);
}

void init_img(t_map *map)
{
    int x;
    int y;
    
    img_loading(map);
    y = 0;
    printf("map->y = %d\n", map->y);
    while (y < map->y)
    {
        x = 0;
        printf("map->x = %d\n", map->x);
        while (x < map->x - 1)
        {
            printf("maps[y][x] = %c\n", map->maps[y][x]);
            if (map->maps[y][x] == '1')
                push_img(map, x * 64, y * 64, map->img_wall);
            if (map->maps[y][x] == '0')
                push_img(map, x * 64, y * 64, map->img_ground); 
            x++;
        }
        y++;
    }
}