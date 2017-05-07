/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:28:35 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/07 04:02:56 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include "mlx.h"
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

void	draw_fractal_pixel(int i, int j, void *mlx, void *window)
{
	double	x;
	double	y;
	double	z;
	double	c;
	int		iteration;
	int		color;

	iteration = 0;
	x = (double)i * 4.0 / WIN_WIDTH - 2;
	y = (double)j * 2 / WIN_HEIGHT - 1;
	z = 0;
	c = 0;
	while (z * z + c * c < 2 * 2 && iteration < 500)
	{
		double tmp = z * z - c * c + x;
		c = 2 * z * c + y;
		z = tmp;
		iteration++;
	}
	color = iteration << 5;
	mlx_pixel_put(mlx, window, i, j, color);
}

void	draw_fractal(void *mlx, void *window)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			draw_fractal_pixel(i, j, mlx, window);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Test fractal");
	draw_fractal(mlx, window);
	mlx_loop(mlx);
}
