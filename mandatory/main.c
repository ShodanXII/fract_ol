/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achat <achat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:55:24 by achat             #+#    #+#             */
/*   Updated: 2025/01/25 16:37:58 by achat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if ((2 == ac && (!ft_strncmp(av[1], "mandelbrot", 10) && 
				ft_strlen(av[1]) == 10))
		|| (4 == ac && (!ft_strncmp(av[1], "julia", 5) && 
				ft_strlen(av[1]) == 5)))
	{
		fractal.fractal_name = av[1];
		if (4 == ac && !ft_strncmp(av[1], "julia", 5))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		data_init(&fractal, fractal.fractal_name);
		fractal_init(&fractal);
		fract_ol_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Error: invalid fractal name use mandelbrot or julia\n", 2);
		return (1);
	}
	return (0);
}
