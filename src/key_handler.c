/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:55:39 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 17:02:18 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	keys_3d(int key, t_fdf *data)
{
	if (key == RIGHT)
	{
		data->shift_x += 10.0;
		data->shift_y -= 10.0;
	}
	else if (key == LEFT)
	{
		data->shift_x -= 10.0;
		data->shift_y += 10.0;
	}
	if (key == UP)
		data->increase_z += 10;
	if (key == DOWN)
		data->increase_z -= 10;
	if (key == W)
		data->z_scale += 1;
	if (key == S)
		data->z_scale -= 1;
}

static void	keys_2d(int key, t_fdf *data)
{
	if (key == RIGHT)
		data->shift_x += 10.0;
	else if (key == LEFT)
		data->shift_x -= 10.0;
	else if (key == UP)
		data->shift_y -= 20.0;
	else if (key == DOWN)
		data->shift_y += 20.0;
}

void	zoom_key_handler(int key, t_fdf *data)
{
	int	delta;

	if (key == PLUS || (key == MINUS && data->zoom - 2 > 0))
	{
		if (key == PLUS)
			delta = 1;
		else
			delta = -1;
		data->zoom += 2 * delta;
		if (data->two_d == FALSE)
		{
			data->increase_z += 10 * delta;
			data->shift_x -= 5.0 * delta;
			data->shift_y += 5.0 * delta;
		}
	}
}

void	keys(int key, t_fdf *data)
{
	if (data->two_d == FALSE)
		keys_3d(key, data);
	else if (data->two_d == TRUE)
		keys_2d(key, data);
	if ((key == PLUS) || (key == MINUS && data->zoom - 2 > 0))
		zoom_key_handler(key, data);
	if ((key == PLUS) || (key == MINUS && data->zoom - 2 > 0))
		zoom_key_handler(key, data);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == P)
		two_d_handler(key, data);
	if (key == ESCAPE)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	if ((key >= 123 && key <= 126) || key == MINUS || key == PLUS || key == W
		|| key == S || key == ESCAPE || key == P)
	{
		keys(key, data);
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		visualize(data);
	}
	return (0);
}
