#ifndef SO_LONG_H
# define SO_LONG_H

#include "./libft/libft.h"
#include "./mlx/mlx.h"
# if defined(__APPLE__) && defined(__MACH__)
#  include "./mlx/mlx.h"

# else
#  include "./mlx-linux/mlx.h"
# endif

int	check_arg(int argc, char **argv);


#endif
