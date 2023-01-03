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
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_key_hook(mlx_win, deal_key, (void*)0);
	mlx_mouse_hook(mlx_win, deal_mouse, (void*)0);
	
	int	fd;
	int i;

	fd = open("./maps/map1.ber", 0);
	i = 0;
	while (i < 5)
	{	
		ft_printf(get_next_line(fd));
		i++;
	}
	mlx_hook(mlx_win, 17, 0, close_window, 0);	
	mlx_loop(mlx);
	return (0);
}
