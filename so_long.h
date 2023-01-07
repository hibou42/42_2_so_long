#ifndef SO_LONG_H
# define SO_LONG_H

# if defined(__APPLE__) && defined(__MACH__)
#  include "./mlx/mlx.h"

# else
#  include "./mlx-linux/mlx.h"
# endif

#include "./libft/libft.h"

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
    void    *img_ground;
    void    *img_wall;
    char	**maps;
    int     x;
    int     y;
    int     img_x;
    int     img_y;
    
}		t_map;

int	check_arg(int argc, char **argv);
void init_map(char **argv, t_map *map);
void check_tab(t_map *map);
int	close_window(void *param);
int free_and_exit(t_map *map);
void init_img(t_map *map);

#endif