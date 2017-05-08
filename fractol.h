/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 16:46:05 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/07 23:38:11 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <complex.h>
# include <X11/X.h>
# ifdef __APPLE__
#  include "mlx.h"
# elif __linux__
#  include <mlx.h>
# endif
# include "libft.h"
# include "keys.h"
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_KEYS 5
# define KEY_UP 0
# define KEY_DOWN 1
# define KEY_LEFT 2
# define KEY_RIGHT 3
# define KEY_ESC 4

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
	double				x;
	double				y;
	double				zoom;
	double				t_x;
	double				t_y;
	int					max_iter;
	t_window			*w;
	int					keys[MAX_KEYS];
	struct s_fractol	*next;
}						t_fractol;

/*
** Setup
*/

t_fractol				*setup_fractol(void *mlx, char **av);
void					setup_hook(t_fractol *list);

/*
** Hooks
*/

int						key_press_hook(int key, t_fractol *fractol);
int						key_release_hook(int key, t_fractol *fractol);
int						loop_hook(t_fractol *list);
int						mouse_hook(int button, int x, int y,
						t_fractol *fractol);
int						exit_window_hook(t_fractol *list);

void					check_keys(t_fractol *fractol);
void					draw_fractol(t_fractol *fractol);

/*
** Fractals
*/

int						get_color(int c);
int						mandelbrot(double complex c, double complex z, int iter,
						const int max_iter);

#endif
