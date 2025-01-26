/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achat <achat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:37:19 by achat             #+#    #+#             */
/*   Updated: 2025/01/25 16:02:04 by achat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->window);
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		close_handler(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (button == 4)
		fractal->zoom *= 1.1;
	else if (button == 5)
		fractal->zoom /= 1.1;
	fract_ol_render(fractal);
	return (0);
}

int	close_window(t_fractal *fractal)
{
	free(fractal->mlx_connection);
	exit(0);
	return (0);
}
