/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achat <achat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:08:40 by achat             #+#    #+#             */
/*   Updated: 2025/01/21 13:42:10 by achat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->fractal_name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	burningship(t_complex *z, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->fractal_name, "burningship", 11))
	{
		z->x = fabs(z->x);
		z->y = fabs(z->y);
	}
	else
	{
		z->x = z->x;
		z->y = z->y;
	}
}

void	handel_pixel(int x, int y, t_fractal fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = map(x, (t_map_range){0, WIDTH}, (t_map_range){fractal.range1.start, 
			fractal.range1.stop}) + fractal.shift_x;
	z.y = map(y, (t_map_range){0, HEIGHT}, (t_map_range){fractal.range2.start, 
			fractal.range2.stop}) + fractal.shift_y;
	julia(&z, &c, &fractal);
	i = 0;
	while (i < fractal.iterations)
	{
		burningship(&z, &fractal);
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal.escape)
		{
			color = map(i, (t_map_range){0, fractal.iterations}, 
					(t_map_range){COLOR_BLACK, COLOR_RED});
			my_pixel_put(x, y, &fractal.img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal.img, COLOR_BLACK);
}

void	fract_ol_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handel_pixel(x, y, *fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, 
		fractal->window, fractal->img.img_ptr, 0, 0);
}
