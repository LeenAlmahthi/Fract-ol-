/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <lalmahth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:40:11 by lalmahth          #+#    #+#             */
/*   Updated: 2025/02/14 12:14:08 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	count_double(t_data *data, int i, double n)
{
	int	count;

	count = 0;
	while (data->argv_j[i] >= '0' && data->argv_j[i] <= '9')
	{
		if (count >= 1)
			count++;
		n *= 10;
		n += data->argv_j[i] - '0';
		if (data->argv_j[i + 1] == '.')
		{
			i++;
			count++;
		}
		i++;
	}
	while (count != 1)
	{
		n *= (float)1 / 10.0;
		count--;
	}
	return (n);
}

double	ft_atoi_f(t_data *data, char *nptr)
{
	int		i;
	int		s;
	double	n;

	s = 1;
	n = 0;
	i = 0;
	data->argv_j = nptr;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		return (3.0);
	n = count_double(data, i, n);
	return (n * s);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if ((n == 0) || (!s1 && !s2))
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && x < n - 1)
	{
		s1++;
		s2++;
		x++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	initialize_data(t_data *data)
{
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->min_x = -2.0;
	data->max_x = 2.0;
	data->min_y = -2.0;
	data->max_y = 2.0;
	data->zoom = 1;
}
