/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:04:19 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 18:43:12 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_dimensions(t_fdf *data)
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
		handle_empty_file();
	while (data->split[data->width] && data->split[data->width][0] != '\n')
		data->width++;
	ft_free_split(data->split);
}

void	read_lines(t_fdf *data)
{
	read_dimensions(data);
	data->lines = (char **)ft_calloc(sizeof(char *), data->height + 1);
	if (!data->lines)
	{
		free_t_fdf(data);
		return ;
	}
	close(data->fd);
}

void	stash_file(t_fdf *data)
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

void	init_z_matrix(t_fdf *data)
{
	int	i;
	int	j;
	int	element;

	i = -1;
	while (++i < data->height)
	{
		data->split = ft_split(data->lines[i], ' ');
		// error handling
		j = -1;
		while (++j < data->width)
		{
			element = ft_atoi(data->split[j]);
			data->z_matrix[i][j].z = element;
			if (numlength((int)element,
					10) < (int)ft_strlen(data->split[j]) - 1)
			{
				data->s_color = ft_strchr(data->split[j], ',');
				data->s_color += 1;
				data->z_matrix[i][j].color = ft_atoi_base(data->s_color);
			}
			else
				data->z_matrix[i][j].color = 0;
		}
		ft_free_split(data->split);
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int	i;

	data->fd = open(file_name, O_RDONLY);
	// if (data->fd == 0 || data->fd < 0)
	// 	error(data->fd, 0);
	read_lines(data);
	data->fd = open(file_name, O_RDONLY, 0);
	// if (data->fd == -1)
	// 	error(data->fd, 0);
	stash_file(data);
	// if (!data->lines)
	// 	error(data->lines, 1);
	data->z_matrix = (t_matrix **)malloc(sizeof(t_matrix *) * data->height);
	// if (!data->z_matrix)
	// 	error(data->z_matrix, 0);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (t_matrix *)malloc(sizeof(t_matrix) * data->width);
		if (!data->z_matrix[i])
		{
			perror("fdf");
			exit(1);
		}
		i++;
	}
	init_z_matrix(data);
}
