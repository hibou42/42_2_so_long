/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/06 16:19:22 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int wall_check(t_map *map)
{
    int res;
    
    int tmp = map->y;
    tmp = 0;

    res = 0;
    return (res);
}

int x_check(t_map *map)
{
    int res;
    int tmp;
    int i;

    res = 0;
    i = 0;
    while (i < map->y)
    {
        tmp = ft_strlen(map->maps[i]);
        printf("map[i] = %d\n", tmp);
        if (tmp != map->x)
            res = 1;
        i++;
    }
    return (res);
}

int y_check(t_map *map)
{
    if (map->y < 3)
        return (1);
    return (0);
}

void check_tab (t_map *map)
{
    int res;
    
    res = 0;
    res += y_check(map);
    res += x_check(map);
    res += wall_check(map);
    printf("x = %d\n", map->x);
    printf("res = %d\n", res);
    if (res > 0)
        free_and_exit(map);
}