/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:00:12 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/07 23:37:53 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
static void	draw_fractal_pixel(int i, int j, t_fractol *f)
{
	double	x;
	double	y;
	double	z;
	double	c;
	int		iteration;
	int		color;

	iteration = 0;
	x = ((double)i * 4.0 / (double)WIN_WIDTH - 2.0) / f->zoom + f->t_x;
	y = ((double)j * 4.0 / (double)WIN_HEIGHT - 2.0) / f->zoom + f->t_y;
	z = 0;
	c = 0;
	while (z * z + c * c < 2 * 2 && iteration < 50)
	{
		double tmp = z * z - c * c + x;
		c = 2 * z * c + y;
		z = tmp;
		iteration++;
	}
	color = iteration << 7;
	mlx_pixel_put(f->w->mlx, f->w->window, i, j, color);
}
*/
void		draw_fractol(t_fractol *f)
{
	int		i;
	int		j;
	double complex	c;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			//draw_fractal_pixel(i, j, fractol);
			c = (((double)i * 4.0 / (double)WIN_WIDTH - 2.0) / f->zoom + f->t_x)
				+
				(((double)j * 4.0 / (double)WIN_HEIGHT - 2.0) / f->zoom + f->t_y)
				* I;
			mlx_pixel_put(f->w->mlx, f->w->window, i, j,
			get_color(mandelbrot(c, 0, 0, f->max_iter)));
			j++;
		}
		i++;
	}
}
