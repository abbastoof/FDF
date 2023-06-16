/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:50:36 by atoof             #+#    #+#             */
/*   Updated: 2023/05/02 14:56:55 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_info(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, Y - 100, 0xFFFFFF,
		"zoom        -> - / +");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, Y - 80, 0xFFFFFF,
		"move        -> use arrow keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, Y - 60, 0xFFFFFF,
		"z axis      -> w / s");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, Y - 40, 0xFFFFFF,
		"projection  -> p");
}

int	mouse_handler(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_z_matrix(data);
	exit(0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < X && y < Y)
	{
		dst = data->addr + (y * data->line_length + (x * (data->bits_per_pixel
						/ 8)));
		*(unsigned int *)dst = color;
	}
}

void	create_window(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, X, Y, "FDF");
	default_settings(data);
}

void	visualize(t_fdf *data)
{
	data->img = mlx_new_image(data->mlx_ptr, X, Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	init_points(data, data->p1, data->p2);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	key_info(data);
	mlx_hook(data->win_ptr, 2, 1L << 1, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx_ptr);
}
