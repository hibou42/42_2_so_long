/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:20:27 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/03 15:20:41 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char **argv, int size_argv)
{
	int	res;

	res = 0;
	if (argv[1][size_argv - 4] != '.')
		res = 1;
	if (argv[1][size_argv - 3] != 'b')
		res = 1;
	if (argv[1][size_argv - 2] != 'e')
		res = 1;
	if (argv[1][size_argv - 1] != 'r')
		res = 1;
	return (res);
}

int	check_arg (int argc, char **argv)
{
	int	size_argv;

	size_argv = 0;
	while (argv[1][size_argv] != '\0')
		size_argv ++;
	if (argc != 2)
	{
		ft_printf("Les arguments ne sont pas bons...\n");
		exit(0);
	}
	if (check_extension(argv, size_argv) == 1)
	{
		ft_printf("Probleme d'extension \n");
		exit(0);
	}
	return (0);
}
