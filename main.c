/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:40:23 by lalmahth          #+#    #+#             */
/*   Updated: 2025/02/14 13:24:59 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	zoom_factor;
	double	x_c;
	double	y_c;

	zoom_factor = 1.05;
	x_c = x / (double)WIDTH * (data->max_x - data->min_x) + data->min_x;
	y_c = y / (double)HEIGHT * (data->max_y - data->min_y) + data->min_y;
	if (button == 4)
	{
		data->min_x = x_c + (data->min_x - x_c) / zoom_factor;
		data->max_x = x_c + (data->max_x - x_c) / zoom_factor;
		data->min_y = y_c + (data->min_y - y_c) / zoom_factor;
		data->max_y = y_c + (data->max_y - y_c) / zoom_factor;
	}
	else if (button == 5)
	{
		data->min_x = x_c + (data->min_x - x_c) * zoom_factor;
		data->max_x = x_c + (data->max_x - x_c) * zoom_factor;
		data->min_y = y_c + (data->min_y - y_c) * zoom_factor;
		data->max_y = y_c + (data->max_y - y_c) * zoom_factor;
	}
	read_mandelbrot_julia(data);
	return (0);
}

int	initialize_mlx(t_data *data)
{
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Leen!");
	if (data->win == NULL)
	{
		free(data->mlx);
		return (1);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
	{
		free(data->win);
		free(data->mlx);
		return (1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
	{
		free(data->img);
		free(data->win);
		free(data->mlx);
		return (1);
	}
	return (0);
}

int	check_input(t_data *data, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
		{
			write(1, "Error\ninput parameters\n", 24);
			return (0);
		}
		data->error = 2;
		return (2);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		data->error = 3;
		return (3);
	}
	write(1, "Error\ninput name Fractal\n", 24);
	return (0);
}

int	check_number(t_data *data, char **argv)
{	
	data->julia_x = ft_atoi_f(data, argv[2]);
	data->julia_y = ft_atoi_f(data, argv[3]);
	if (data->julia_x >= -2 && data->julia_x <= 2
		&& data->julia_y >= -2 && data->julia_y <= 2)
		return (0);
	write(1, "Error\ninput number from range -2 to 2\n", 39);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc >= 2)
	{
		if (!check_input(&data, argc, argv))
			return (1);
		if (data.error == 2 && check_number(&data, argv) == 1)
			return (1);
		data.mlx = mlx_init();
		if (initialize_mlx(&data) == 1)
		{
			ft_free(&data);
			return (1);
		}
		initialize_data(&data);
		read_mandelbrot_julia(&data);
		mlx_hook(data.win, 4, 1L << 2, mouse_hook, &data);
		mlx_hook(data.win, 17, 0, close_win_x, &data);
		mlx_hook(data.win, 2, 1L << 0, close_win, &data);
		mlx_loop(data.mlx);
	}
	else
		write(1, "Error\ninput Fractal name \n", 25);
	return (0);
}
