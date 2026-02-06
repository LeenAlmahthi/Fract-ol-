/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:21 by lalmahth          #+#    #+#             */
/*   Updated: 2025/02/12 17:59:25 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIDTH 900
# define HEIGHT 900
# define MAX_X 2
# define MIN_X -2
# define MAX_Y 2
# define MIN_Y -2

# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	char	*argv_j;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mouse_x;
	int		mouse_y;
	int		error;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	real_c;
	double	imag_c;
	double	real_z;
	double	imag_z;
}	t_data;

double	count_double(t_data *data, int i, double n);
double	ft_atoi_f(t_data *data, char *nptr);
void	put_pixel_to_image(t_data *data, int x, int y, int color);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	draw_in_image_2(t_data *data, int x, int y, int i);
int		length_2_point(t_data *data);
void	draw_in_image(t_data *data, int x, int y);
void	convert_to_complex(int x, int y, t_data *data);
void	read_mandelbrot_julia(t_data *data);
int		check_input(t_data *data, int argc, char **argv);
void	ft_free(t_data *data);
int		close_win(int button, t_data *data);
int		close_win_x(t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		initialize_mlx(t_data *data);
void	initialize_data(t_data *data);

#endif
