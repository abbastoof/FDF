/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:28:37 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 19:38:15 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_z_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	if (data->z_matrix)
	{
		while (i < data->height)
		{
			if (data->z_matrix[i])
				free(data->z_matrix[i]);
			i++;
		}
		free(data->z_matrix);
	}
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

void	handle_error(t_fdf *data, int error_code)
{
	const char	*error_messages[] = {
		"Error opening file",
		"Error reading lines",
		"Error allocating memory for z_matrix",
		"Error allocating memory for z_matrix row",
		"Error: Empty file"};

	if (error_code == 2 || error_code == 3)
		free_z_matrix(data);
	if (error_code == 1)
		free_t_fdf(data);
	if (error_code >= 0 && error_code < (int)(sizeof(error_messages)
		/ sizeof(error_messages[0])))
	{
		if (error_code == 4)
			ft_printf("%s (%d)\n", error_messages[error_code], errno);
		else
			perror(error_messages[error_code]);
	}
	else
		perror("Unknown error");
	exit(1);
}
