/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:27:04 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/06 17:46:31 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_window	*setup_window(void *mlx, int type)
{
	t_window	*window;
	const char	*name[] = {"", "Julia", "Mandelbrot", "Sierpinsky carpet"};

	window = malloc(sizeof(t_window));
	window->width = WINDOW_WIDTH;
	window->height = WINDOW_HEIGHT;
	window->mlx = mlx;
	window->window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
									(char*)name[type]);
	return (window);
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
		(*cur)->type = ft_atoi(*av);
		(*cur)->window = setup_window(mlx, (*cur)->type);
		(*cur)->next = NULL;
		cur = &(*cur)->next;
	}
	return (list);
}
