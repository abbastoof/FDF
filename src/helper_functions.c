/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:01:56 by atoof             #+#    #+#             */
/*   Updated: 2023/05/01 15:03:19 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

int	numlength(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = (n / base);
		i++;
	}
	return (i);
}
