/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:22:21 by lalmahth          #+#    #+#             */
/*   Updated: 2026/02/06 16:33:25 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_in_image_2(t_data *data, int x, int y, int i)
{
	int		r;
	int		g;
	int		b;
	int		color;
	double	t;

	t = i / 50.0;
	r = (int)(5 * t * t * t * 255);
g = (int)(8 * t * t * 255);
b = (int)(12 * t * 255);
	color = (r << 16) | (g << 8) | b;
	put_pixel_to_image(data, x, y, color);
}

int	length_2_point(t_data *data)
{
	int	re;

	re = data->real_z * data->real_z + data->imag_z * data->imag_z;
	re = sqrt(re);
	return (re);
}

void	draw_in_image(t_data *data, int x, int y)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < 50)
	{
		tmp = (data->real_z * data->real_z)
			-(data->imag_z * data->imag_z) + data->real_c;
		data->imag_z = 2 * (data->real_z * data->imag_z) + data->imag_c;
		data->real_z = tmp;
		if (length_2_point(data) > 2)
			break ;
		i++;
	}
	if (i != 50)
		draw_in_image_2(data, x, y, i);
	else if (i == 50)
		put_pixel_to_image(data, x, y, 0x000000);
}

void	convert_to_complex(int x, int y, t_data *data)
{
	if (data->error == 3)
	{
		data->real_c = x / (double)WIDTH
			* (data->max_x - data->min_x) + data->min_x;
		data->imag_c = y / (double)HEIGHT
			* (data->max_y - data->min_y) + data->min_y;
		data->real_z = 0;
		data->imag_z = 0;
	}
	else if (data->error == 2)
	{
		data->real_c = data->julia_x;
		data->imag_c = data->julia_y;
		data->real_z = x / (double)WIDTH
			* (data->max_x - data->min_x) + data->min_x;
		data->imag_z = y / (double)HEIGHT
			* (data->max_y - data->min_y) + data->min_y;
	}
	data->real_c *= data->zoom;
	data->imag_c *= data->zoom;
	draw_in_image(data, x, y);
}

void	read_mandelbrot_julia(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			convert_to_complex(x, y, data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
