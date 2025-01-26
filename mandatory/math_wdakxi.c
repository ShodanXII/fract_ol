/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_wdakxi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achat <achat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:41:01 by achat             #+#    #+#             */
/*   Updated: 2025/01/21 12:38:16 by achat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, t_map_range range1, t_map_range range2)
{
	return (range2.start + (range2.stop - range2.start) 
		* ((value - range1.start) / (range1.stop - range1.start)));
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = z.x * z.x - z.y * z.y;
	result.y = 2 * z.x * z.y;
	return (result);
}
