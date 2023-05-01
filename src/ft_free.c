/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:58:40 by atoof             #+#    #+#             */
/*   Updated: 2023/04/24 20:44:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_fdf *data, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < data->height)
		{
			free(data->z_matrix[i]);
			i++;
		}
	}
	free(data->z_matrix);
	free(data);
	exit (0);
}

