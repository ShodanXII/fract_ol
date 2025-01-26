/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achat <achat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:37:19 by achat             #+#    #+#             */
/*   Updated: 2025/01/23 16:30:46 by achat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->window);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	double	range_width;
	double	range_height;
	double	shift_factor;

	range_width = fractal->range1.stop - fractal->range1.start;
	range_height = fractal->range2.stop - fractal->range2.start;
	shift_factor = 0.05;
	if (keycode == 53)
		close_handler(fractal);
	else if (keycode == 123)
		fractal->shift_x -= range_width * shift_factor;
	else if (keycode == 124)
		fractal->shift_x += range_width * shift_factor;
	else if (keycode == 125)
		fractal->shift_y += range_height * shift_factor;
	else if (keycode == 126)
		fractal->shift_y -= range_height * shift_factor;
	else if (keycode == 69)
		fractal->iterations += 1;
	else if (keycode == 78)
		fractal->iterations -= 1;
	fract_ol_render(fractal);
	return (0);
}

void	update_ranges(t_fractal *fractal, double zoom_factor, 
		double mouse_re, double mouse_im)
{
	double	range_width;
	double	range_height;

	range_width = fractal->range1.stop - fractal->range1.start;
	range_height = fractal->range2.stop - fractal->range2.start;
	fractal->range1.start = mouse_re - 
		(mouse_re - fractal->range1.start) * zoom_factor;
	fractal->range1.stop = mouse_re + 
		(fractal->range1.stop - mouse_re) * zoom_factor;
	fractal->range2.start = mouse_im - 
		(mouse_im - fractal->range2.start) * zoom_factor;
	fractal->range2.stop = mouse_im + 
		(fractal->range2.stop - mouse_im) * zoom_factor;
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	mouse_re = map(x, (t_map_range){0, WIDTH},
			(t_map_range){fractal->range1.start, fractal->range1.stop});
	mouse_im = map(y, (t_map_range){0, HEIGHT},
			(t_map_range){fractal->range2.start, fractal->range2.stop});
	update_ranges(fractal, zoom_factor, mouse_re, mouse_im);
	fract_ol_render(fractal);
	return (0);
}

int	close_window(t_fractal *fractal)
{
	free(fractal->mlx_connection);
	exit(0);
	return (0);
}
