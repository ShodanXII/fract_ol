/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achat <achat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:44:10 by achat             #+#    #+#             */
/*   Updated: 2025/01/25 16:54:43 by achat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	ft_putstr_fd("Error: malloc failed\n", 2);
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal, const char *fractal_name)
{
	fractal->escape = 4.0;
	fractal->iterations = 51;
	fractal->range1.start = -2.0;
	fractal->range1.stop = 2.0;
	fractal->range2.start = -2.0;
	fractal->range2.stop = 2.0;
	fractal->zoom = 1.0;
	fractal->fractal_name = fractal_name;
}

static void	events(t_fractal *fractal)
{
	mlx_hook(fractal->window, 2, 1L << 0, key_handler, fractal);
	mlx_hook(fractal->window, 4, 0, mouse_handler, fractal);
	mlx_hook(fractal->window, 17, 0, close_window, fractal);
	mlx_loop(fractal->mlx_connection);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, (char *)fractal->fractal_name);
	if (NULL == fractal->window)
	{
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal, fractal->fractal_name);
	fract_ol_render(fractal);
	events(fractal);
}
