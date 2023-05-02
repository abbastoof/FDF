/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:05:38 by atoof             #+#    #+#             */
/*   Updated: 2023/05/02 14:07:59 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colors(t_fdf *data, t_point p1, t_point p2)
{
	int	z1;
	int	z2;
	int	color1;
	int	color2;

	z1 = data->z_matrix[(int)p1.y][(int)p1.x].z;
	z2 = data->z_matrix[(int)p2.y][(int)p2.x].z;
	color1 = data->z_matrix[(int)p1.y][(int)p1.x].color;
	color2 = data->z_matrix[(int)p2.y][(int)p2.x].color;
	if (color1 != 0)
		return (color1);
	if (color2 != 0)
		return (color2);
	if (z1 == 0 || z2 == 0)
		return (0xFFD700);
	else if (z2 > z1)
		return (0x6B8E23);
	else
		return (0xCD5C5C);
}
