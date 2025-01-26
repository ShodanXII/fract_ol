/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achat <achat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:46:48 by achat             #+#    #+#             */
/*   Updated: 2025/01/23 15:46:20 by achat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

# define COLOR_BLACK 0x000000
# define COLOR_RED 0xFF0000

typedef struct s_complex {
	double	x;
	double	y;
}	t_complex;

typedef struct s_map_range {
	double	start;
	double	stop;
}	t_map_range;

typedef struct s_img {
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal {
	int			iterations;
	double		escape;
	t_map_range	range1;
	t_map_range	range2;
	t_img		img;
	void		*mlx_connection;
	void		*window;
	const char	*fractal_name;
	double		shift_x;
	double		shift_y;
	double		julia_x;
	double		julia_y;
}	t_fractal;

void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal, const char *fractal_name);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		map(double value, t_map_range range1, t_map_range range2);
void		ft_putstr_fd(char *s, int fd);
void		fract_ol_render(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
size_t		ft_strlen(const char *s);
void		update_ranges(t_fractal *fractal, double zoom_factor,
				double mouse_re, double mouse_im);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		atodbl(char *s);
int			close_window(t_fractal *fractal);

#endif