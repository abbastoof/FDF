/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:47:57 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 15:59:09 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_settings(t_fdf *data)
{
	data->shift_x = X / 3;
	data->shift_y = -Y / 200;
	data->zoom = 40;
	data->increase_z = 0;
	data->z_scale = 1;
	data->two_d = FALSE;
}
