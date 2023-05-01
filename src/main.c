/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:03:24 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 16:41:41 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	data;

	ft_bzero(&data, sizeof(t_fdf));
	if (argc != 2)
	{
		ft_printf("%s <file name>", argv[0]);
		return (-1);
	}
	read_file(argv[1], &data);
	create_window(&data);
	visualize(&data);
	return (0);
}
