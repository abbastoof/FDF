/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:28:37 by atoof             #+#    #+#             */
/*   Updated: 2023/04/24 20:44:09 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(t_fdf **data, int flag)
{
	perror("fdf");
	if (flag == 1)
		ft_free_split((*data)->lines);
	free(data);
	exit(0);
}