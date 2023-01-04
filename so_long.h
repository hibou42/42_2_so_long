#ifndef SO_LONG_H
# define SO_LONG_H

# if defined(__APPLE__) && defined(__MACH__)
#  include "./mlx/mlx.h"

# else
#  include "./mlx-linux/mlx.h"
# endif

#include "./libft/libft.h"

int	check_arg(int argc, char **argv);
int check_map(char **argv);

#endif
