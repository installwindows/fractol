/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:56:32 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/09 19:39:51 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	static int	z;

	if (button == SCROLL_UP)
	{
		fractol->zoom *= 1.05;
		z++;
		if (z % 40 == 0)
			fractol->max_iter *= 1.1;
		fractol->x = x;
		fractol->y = y;
		fractol->redraw = 1;
		//draw_fractol(fractol);
	}
	if (button == SCROLL_DOWN)
	{
		fractol->zoom /= 1.05;
		z--;
		if (z % 40 == 0)
			fractol->max_iter /= 1.1;
		if (z < 0)
			z = 0;
		if (fractol->max_iter < 20)
			fractol->max_iter = 20;
		if (fractol->zoom < 1)
			fractol->zoom = 1;
		fractol->x = x;
		fractol->y = y;
		fractol->redraw = 1;
		//draw_fractol(fractol);
	}
	return (0);
}

int		key_press_hook(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit(0);
	if (key == UP)
		fractol->keys[KEY_UP] = 1;
	if (key == DOWN)
		fractol->keys[KEY_DOWN] = 1;
	if (key == LEFT)
		fractol->keys[KEY_LEFT] = 1;
	if (key == RIGHT)
		fractol->keys[KEY_RIGHT] = 1;
	return (0);
}

int		key_release_hook(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit(0);
	if (key == UP)
		fractol->keys[KEY_UP] = 0;
	if (key == DOWN)
		fractol->keys[KEY_DOWN] = 0;
	if (key == LEFT)
		fractol->keys[KEY_LEFT] = 0;
	if (key == RIGHT)
		fractol->keys[KEY_RIGHT] = 0;
	return (0);
}

int		loop_hook(t_fractol *list)
{
	t_fractol	*cur;

	cur = list;
	while (cur)
	{
		check_keys(cur);
		if (cur->redraw)
		{
			draw_image(cur, mandelbrot);
			cur->redraw = 0;
		}
		//check_mouse
		cur = cur->next;
	}
	return (0);
}

int		exit_window_hook(t_fractol *list)
{
	mlx_destroy_window(list->w->mlx, list->w->window);
	return (0);
}
