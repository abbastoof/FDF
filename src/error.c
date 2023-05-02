/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:28:37 by atoof             #+#    #+#             */
/*   Updated: 2023/05/02 16:44:01 by atoof            ###   ########.fr       */
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

const char	*get_error_message(int error_code)
{
	static const char	*error_messages[NUM_ERROR_MESSAGES] = {
		"Error opening file",
		"Error reading lines",
		"Error allocating memory for z_matrix",
		"Error allocating memory for z_matrix row",
		"Error: Empty file",
		"Error splitting line"};

	if (error_code >= 0 && error_code < NUM_ERROR_MESSAGES)
		return (error_messages[error_code]);
	return ("Unknown error");
}

void	handle_error(t_fdf *data, int error_code)
{
	const char	*error_message;
	int			k;

	error_message = get_error_message(error_code);
	if (error_code == 1)
		free_t_fdf(data);
	else if (error_code == 2 || error_code == 3)
		free_z_matrix(data);
	else if (error_code == 4)
		ft_printf("%s (%d)\n", error_message, errno);
	else if (error_code == 5)
	{
		k = 0;
		while (k < data->height)
		{
			free(data->lines[k]);
			k++;
		}
		free(data->lines);
	}
	else
		perror(error_message);
	exit(1);
}
