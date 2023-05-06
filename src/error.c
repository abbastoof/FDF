/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:28:37 by atoof             #+#    #+#             */
/*   Updated: 2023/05/02 19:10:57 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
	return ;
}

void	free_z_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
}

void	free_t_fdf(t_fdf *data)
{
	int	i;

	i = 0;
	if (data->lines)
	{
		while (i < data->height)
		{
			if (data->lines[i])
				free(data->lines[i]);
			i++;
		}
		free(data->lines);
	}
}

void	cleanup_resources(t_fdf *data, int error_code)
{
	int	k;

	if (error_code == 1)
		free_t_fdf(data);
	else if (error_code == 2 || error_code == 3)
		free_z_matrix(data);
	else if (error_code == 4)
	{
		k = 0;
		while (k < data->height)
		{
			free(data->lines[k]);
			k++;
		}
		free(data->lines);
	}
}

void	handle_error(char **argv, t_fdf *data, int error_code)
{
	if (error_code == 0)
	{
		ft_printf("%s: ", argv[0]);
		perror(argv[1]);
	}
	else
	{
		cleanup_resources(data, error_code);
		ft_printf("%s: ", argv[0]);
		perror(argv[1]);
	}
	exit(1);
}
