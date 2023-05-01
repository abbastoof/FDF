/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:28:37 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 18:40:50 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_empty_file(void)
{
	ft_printf("Error: Empty file (%d)\n", errno);
	exit(EXIT_FAILURE);
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

void	error(t_fdf **data, int flag)
{
	perror("fdf");
	if (flag == 1)
		ft_free_split((*data)->lines);
	free(data);
	exit(0);
}
