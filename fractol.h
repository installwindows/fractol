/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 16:46:05 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/06 17:46:07 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <complex.h>
# include "mlx.h"
# include "libft.h"
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 800

typedef struct			s_window
{
	void				*mlx;
	void				*window;
	int					width;
	int					height;
}						t_window;

typedef struct			s_fractol
{
	int					type;
	t_window			*window;
	struct s_fractol	*next;
}						t_fractol;

t_fractol				*setup_fractol(void *mlx, char **av);

#endif
