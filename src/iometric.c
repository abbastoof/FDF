/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iometric.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:46:22 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 15:02:24 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 2D isometric coordinates
** Compute isometric coordinates from 3D Cartesian coordinates
** using the isometric projection formula 
** 30 degrees = pi/6 radians
** at the end Round coordinates to the nearest integer values
*/

void	isometric(float *x, float *y, int z)
{
	float	iso_x;
	float	iso_y;

	iso_x = (*x - *y) * cosf(M_PI / 6.0);
	iso_y = ((*x + *y) * sinf(M_PI / 6.0)) - z;
	*x = roundf(iso_x);
	*y = roundf(iso_y);
}
