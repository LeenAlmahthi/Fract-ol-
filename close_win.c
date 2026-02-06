/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalmahth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:37:23 by lalmahth          #+#    #+#             */
/*   Updated: 2025/02/12 17:39:14 by lalmahth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_win_x(t_data *data)
{
	ft_free(data);
	exit(0);
	return (0);
}

void	ft_free(t_data *data)
{
	if (data->mlx)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	close_win(int button, t_data *data)
{
	if (button == 65307)
	{
		ft_free(data);
		exit(0);
	}
	return (0);
}
