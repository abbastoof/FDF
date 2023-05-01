/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:39:50 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 17:25:06 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	two_d_handler(int key, t_fdf *data)
{
	if (key == P)
	{
		if (data->two_d == FALSE)
		{
			data->two_d = TRUE;
			data->previous_shift_x = data->shift_x;
			data->previous_shift_y = data->shift_y;
			data->shift_y = 0;
			data->shift_x = 0;
		}
		else
		{
			data->two_d = FALSE;
			data->shift_x = data->previous_shift_x;
			data->shift_y = data->previous_shift_y;
		}
	}
}

void	shifting(t_fdf *data, t_point *p1, t_point *p2)
{
	p1->x += data->shift_x;
	p1->y += data->shift_y;
	p2->x += data->shift_x;
	p2->y += data->shift_y;
	if (data->increase_z != 0)
	{
		p1->z += data->increase_z;
		p2->z += data->increase_z;
	}
}

void	zoom(t_fdf *data, t_point *p1, t_point *p2)
{
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p2->x *= data->zoom;
	p2->y *= data->zoom;
	if (data->z_scale != 0)
	{
		p1->z *= data->z_scale;
		p2->z *= data->z_scale;
	}
}

void	z_init(t_fdf *data, t_point *p1, t_point *p2)
{
	p1->z = data->z_matrix[(int)p1->y][(int)p1->x].z;
	p2->z = data->z_matrix[(int)p2->y][(int)p2->x].z;
}

int	prepare_points(t_fdf *data, t_point *p1, t_point *p2)
{
	int	color;

	z_init(data, p1, p2);
	color = colors(data, *p1, *p2);
	zoom(data, p1, p2);
	shifting(data, p1, p2);
	if (data->two_d == 0)
	{
		isometric(&p1->x, &p1->y, p1->z);
		isometric(&p2->x, &p2->y, p2->z);
	}
	return (color);
}
