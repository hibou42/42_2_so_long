#include "so_long.h"

int main (void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);

	int	fd;
	int i;

	fd = open("./maps/map1.ber", 0);
	i = 0;
	while (i < 5)
	{	
		ft_printf(get_next_line(fd));
		i++;
	}
	return (0);
}
