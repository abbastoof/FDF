/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:04:19 by atoof             #+#    #+#             */
/*   Updated: 2023/05/02 19:10:05 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_dimensions(char **argv, t_fdf *data)
{
	int	flag;

	flag = 0;
	data->width = 0;
	data->height = 0;
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break ;
		data->height++;
		if (flag == 0)
		{
			data->split = ft_split(data->line, ' ');
			flag = 1;
		}
		free(data->line);
	}
	if (!data->split)
		handle_error(argv, data, 4);
	while (data->split[data->width] && data->split[data->width][0] != '\n')
		data->width++;
	ft_free_split(data->split);
}

static void	read_lines(char **argv, t_fdf *data)
{
	read_dimensions(argv, data);
	data->lines = (char **)ft_calloc(sizeof(char *), data->height + 1);
	if (!data->lines)
	{
		handle_error(argv, data, 1);
		return ;
	}
	close(data->fd);
}

static void	stash_file(t_fdf *data)
{
	int	i;

	i = 0;
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break ;
		data->lines[i] = ft_strdup(data->line);
		i++;
		free(data->line);
	}
	close(data->fd);
}

void	read_file(char **argv, t_fdf *data)
{
	int	i;

	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		handle_error(argv, data, 0);
	read_lines(argv, data);
	data->fd = open(argv[1], O_RDONLY, 0);
	if (data->fd == -1)
		handle_error(argv, data, 0);
	stash_file(data);
	data->z_matrix = (t_matrix **)malloc(sizeof(t_matrix *) * data->height);
	if (!data->z_matrix)
		handle_error(argv, data, 2);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (t_matrix *)malloc(sizeof(t_matrix) * data->width);
		if (!data->z_matrix[i])
			handle_error(argv, data, 3);
		i++;
	}
	init_z_matrix(argv, data);
}
