/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_z_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:25:05 by atoof             #+#    #+#             */
/*   Updated: 2023/05/02 16:25:35 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_z_matrix_element(t_fdf *data, int i, int j)
{
	int	element;

	element = ft_atoi(data->split[j]);
	data->z_matrix[i][j].z = element;
	if (numlength((int)element, 10) < (int)ft_strlen(data->split[j]) - 1)
	{
		data->s_color = ft_strchr(data->split[j], ',') + 1;
		data->z_matrix[i][j].color = ft_atoi_base(data->s_color);
	}
	else
		data->z_matrix[i][j].color = 0;
}

void	init_z_matrix(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		data->split = ft_split(data->lines[i], ' ');
		if (!data->split)
			handle_error(data, 5);
		j = 0;
		while (j < data->width)
		{
			set_z_matrix_element(data, i, j);
			j++;
		}
		ft_free_split(data->split);
		i++;
	}
}
