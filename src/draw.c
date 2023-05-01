/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:52:07 by atoof             #+#    #+#             */
/*   Updated: 2023/04/29 22:22:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_steps(int p1, int p2)
{
	if (p1 < p2)
		return (1);
	else
		return (-1);
}

void	bresenham(t_fdf *data, t_point p1, t_point p2)
{
	int	color;

	color = prepare_points(data, &p1, &p2);
	data->delta_x = ft_abs((int)p2.x - (int)p1.x);
	data->delta_y = ft_abs((int)p2.y - (int)p1.y);
	data->steps_x = get_steps((int)p1.x, (int)p2.x);
	data->steps_y = get_steps((int)p1.y, (int)p2.y);
	data->error = data->delta_x - data->delta_y;
	while ((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y)
	{
		my_mlx_pixel_put(data, (int)p1.x, (int)p1.y, color);
		data->e2 = (2 * data->error);
		if (data->e2 > -data->delta_y)
		{
			data->error -= data->delta_y;
			p1.x += data->steps_x;
		}
		if (data->e2 < data->delta_x)
		{
			data->error += (int)data->delta_x;
			p1.y += (int)data->steps_y;
		}
	}
	my_mlx_pixel_put(data, (int)p1.x, (int)p1.y, color);
}

void	init_points(t_fdf *data, t_point p1, t_point p2)
{
	p1.y = -1;
	while (++p1.y < data->height)
	{
		p1.x = -1;
		while (++p1.x < data->width)
		{
			if (p1.x < data->width - 1)
			{
				p2.x = p1.x + 1;
				p2.y = p1.y;
				bresenham(data, p1, p2);
			}
			if (p1.y < data->height - 1)
			{
				p2.y = p1.y + 1;
				p2.x = p1.x;
				bresenham(data, p1, p2);
			}
		}
	}
}
