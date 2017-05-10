/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 22:08:14 by varnaud           #+#    #+#             */
/*   Updated: 2017/05/10 03:32:10 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int c)
{
	/*
	const int colors[] = {0xF0F8FF, 0xFAEBD7, 0x00FFFF, 0x7FFFD4, 0xF0FFFF,
		0xF5F5DC, 0xFFE4C4, 0xFFEBCD, 0x0000FF, 0x8A2BE2, 0xA52A2A, 0xDEB887,
		0x5F9EA0, 0x7FFF00, 0xD2691E, 0xFF7F50, 0x6495ED, 0xFFF8DC, 0xDC143C,
		0x00FFFF, 0x00008B, 0x008B8B, 0xB8860B, 0xA9A9A9, 0xA9A9A9, 0x006400,
		0xBDB76B, 0x8B008B, 0x556B2F, 0xFF8C00, 0x9932CC, 0x8B0000, 0xE9967A,
		0x8FBC8F, 0x483D8B, 0x2F4F4F, 0x2F4F4F, 0x00CED1, 0x9400D3, 0xFF1493,
		0x00BFFF, 0x696969, 0x696969, 0x1E90FF, 0xB22222, 0xFFFAF0, 0x228B22,
		0xFF00FF, 0xDCDCDC, 0xF8F8FF, 0xFFD700, 0xDAA520, 0x808080, 0x808080,
		0x008000, 0xADFF2F, 0xF0FFF0, 0xFF69B4, 0xCD5C5C, 0x4B0082, 0xFFFFF0,
		0xF0E68C, 0xE6E6FA, 0xFFF0F5, 0x7CFC00, 0xFFFACD, 0xADD8E6, 0xF08080,
		0xE0FFFF, 0xFAFAD2, 0xD3D3D3, 0xD3D3D3, 0x90EE90, 0xFFB6C1, 0xFFA07A,
		0x20B2AA, 0x87CEFA, 0x778899, 0x778899, 0xB0C4DE, 0xFFFFE0, 0x00FF00,
		0x32CD32, 0xFAF0E6, 0xFF00FF, 0x800000, 0x66CDAA, 0x0000CD, 0xBA55D3,
		0x9370DB, 0x3CB371, 0x7B68EE, 0x00FA9A, 0x48D1CC, 0xC71585, 0x191970,
		0xF5FFFA, 0xFFE4E1, 0xFFE4B5, 0xFFDEAD, 0x000080, 0xFDF5E6, 0x808000,
		0x6B8E23, 0xFFA500, 0xFF4500, 0xDA70D6, 0xEEE8AA, 0x98FB98, 0xAFEEEE,
		0xDB7093, 0xFFEFD5, 0xFFDAB9, 0xCD853F, 0xFFC0CB, 0xDDA0DD, 0xB0E0E6,
		0x800080, 0x663399, 0xFF0000, 0xBC8F8F, 0x4169E1, 0x8B4513, 0xFA8072,
		0xF4A460, 0x2E8B57, 0xFFF5EE, 0x000080, 0x00008B, 0x0000CD, 0x0000FF,
		0x006400, 0x008000, 0x008080, 0x008B8B, 0x00BFFF, 0x00CED1, 0x00FA9A,
		0x00FF00, 0x00FF7F, 0x00FFFF, 0x00FFFF, 0x191970, 0x1E90FF, 0x20B2AA,
		0x228B22, 0x2E8B57, 0x2F4F4F, 0x2F4F4F, 0x32CD32, 0x3CB371, 0x40E0D0};
*/
	const int	colors[] = {0x2C3539, 0x2B1B17, 0x34282C, 0x25383C, 0x3B3131, 0x413839, 0x3D3C3A, 0x463E3F, 0x4C4646, 0x504A4B, 0x565051, 0x5C5858, 0x625D5D, 0x666362, 0x6D6968, 0x726E6D, 0x736F6E, 0x837E7C, 0x848482, 0xB6B6B4, 0xD1D0CE, 0xE5E4E2, 0xBCC6CC, 0x98AFC7};
	return (colors[c % (sizeof(colors) / sizeof(int))]);
}

int		mandelbrot(double complex z, double complex c, const int max_iter)
{
	int		i;
	
	i = 0;
	while (i < max_iter)
	{
		if (cimag(z) * cimag(z) + creal(z) * creal(z) >= 4)
			break ;
		else
			z = cpow(z, 2) + c;
		i++;
	}
	return (i);
}

int		julia(double complex z, double complex c, const int max_iter)
{
	int		i;

	i = 0;
	while (i < max_iter)
	{
		if (cimag(z) * cimag(z) + creal(z) * creal(z) >= 4)
			break ;
		else
			z = cpow(z, 2) + c;
		i++;
	}
	return (i);
}
