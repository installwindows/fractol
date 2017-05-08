/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:27:04 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/07 23:48:16 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_window	*setup_window(void *mlx, int type)
{
	t_window	*window;
	const char	*name[] = {"", "Julia", "Mandelbrot", "Sierpinsky carpet"};

	window = malloc(sizeof(t_window));
	window->width = WIN_WIDTH;
	window->height = WIN_HEIGHT;
	window->mlx = mlx;
	window->window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT,
									(char*)name[type]);
	return (window);
}

void			setup_hook(t_fractol *list)
{
	t_fractol	*cur;

	cur = list;
	while (cur)
	{
		mlx_hook(cur->w->window, KeyPress, 0, key_press_hook, cur);
		mlx_hook(cur->w->window, KeyRelease, 0, key_release_hook, cur);
		mlx_hook(cur->w->window, DestroyNotify, 0, exit_window_hook, cur);
		mlx_mouse_hook(cur->w->window, mouse_hook, cur);
		cur = cur->next;
	}
	mlx_loop_hook(list->w->mlx, loop_hook, list);
}

t_fractol		*setup_fractol(void *mlx, char **av)
{
	t_fractol	*list;
	t_fractol	**cur;

	list = NULL;
	cur = &list;
	while (*++av)
	{
		*cur = malloc(sizeof(t_fractol));
		ft_memset(*cur, 0, sizeof(t_fractol));
		(*cur)->zoom = 1;
		(*cur)->max_iter = 50;
		(*cur)->type = ft_atoi(*av);
		(*cur)->w = setup_window(mlx, (*cur)->type);
		(*cur)->next = NULL;
		cur = &(*cur)->next;
	}
	return (list);
}
