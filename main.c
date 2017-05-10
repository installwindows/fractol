/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 16:44:33 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/09 16:33:14 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	validate_arguments(int ac, char **av)
{
	int		c;

	if (ac == 1 || ac > 3)
		return (1);
	while (*++av)
	{
		c = ft_atoi(*av);
		if (c < 1 || c > 3)
			return (1);
	}
	return (0);
}

static void	usage(void)
{
	ft_fprintf(2, "usage: fractol [num]...\n");
	ft_fprintf(2, "       1. Julia\n");
	ft_fprintf(2, "       2. Mandelbrot\n");
	ft_fprintf(2, "       3. Sierpinski carpet\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_fractol	*list;
	void		*mlx;

	if (validate_arguments(argc, argv))
		usage();
	mlx = mlx_init();
	list = setup_fractol(mlx, argv);
	setup_hook(list);
	while (list)
	{
		draw_image(list, mandelbrot);
		list = list->next;
	}
	mlx_loop(mlx);
}
