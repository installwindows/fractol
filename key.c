/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:26:06 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/09 16:34:47 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_keys(t_fractol *fractol)
{
	double	ty;
	double	tx;

	ty = fractol->t_y;
	tx = fractol->t_x;
	if (fractol->keys[KEY_UP])
		ty -= 1.0 / fractol->zoom;
	if (fractol->keys[KEY_DOWN])
		ty += 1.0 / fractol->zoom;
	if (fractol->keys[KEY_LEFT])
		tx -= 1.0 / fractol->zoom;
	if (fractol->keys[KEY_RIGHT])
		tx += 1.0 / fractol->zoom;
	if (ty != fractol->t_y || tx != fractol->t_x)
	{
		fractol->t_y = ty;
		fractol->t_x = tx;
		fractol->redraw = 1;
		//draw_fractol(fractol);
	}
}
