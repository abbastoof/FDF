/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:02:17 by atoof             #+#    #+#             */
/*   Updated: 2023/05/02 16:26:26 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ------------------------------program structure-----------------------------
** 1. read file
** 		- get height(how many lines) of text
**		- get width(how many numbers in line)
**		- allocate memory for **int by using width and height (ft_split)
**		- read file and write number into **int matrix
**				by using ft_split() and ft_atoi()
** -------------
*/

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1
# define ERROR
# define X 1024
# define Y 768
# define ESCAPE 53
# define W 13
# define S 1
# define P 35
# define PLUS 24
# define MINUS 27
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define NUM_ERROR_MESSAGES 6


typedef struct s_matrix
{
	int				z;
	unsigned int	color;
}					t_matrix;

typedef struct s_point
{
	float			x;
	float			y;
	int				z;
}					t_point;

typedef struct s_fdf
{
	int				width;
	int				height;
	int				fd;
	char			*s_color;
	char			*line;
	char			**lines;
	char			**split;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	float			delta_x;
	float			delta_y;
	float			steps_x;
	float			steps_y;
	int				error;
	int				e2;
	int				zoom;
	float			shift_x;
	float			shift_y;
	int				increase_z;
	int				two_d;
	int				z_scale;
	float			previous_shift_x;
	float			previous_shift_y;
	t_point			p1;
	t_point			p2;
	t_matrix		**z_matrix;
}					t_fdf;

void				default_settings(t_fdf *data);
void				read_file(char *file_name, t_fdf *data);
void				init_z_matrix(t_fdf *data);
void				handle_error(t_fdf *data, int error_code);
void				free_t_fdf(t_fdf *data);
void				create_window(t_fdf *data);
void				visualize(t_fdf *data);
int					deal_key(int key, t_fdf *data);
void				two_d_handler(int key, t_fdf *data);
void				zoom_key_handler(int key, t_fdf *data);
void				z_init(t_fdf *data, t_point *p1, t_point *p2);
void				shifting(t_fdf *data, t_point *p1, t_point *p2);
void				zoom(t_fdf *data, t_point *p1, t_point *p2);
void				isometric(float *x, float *y, int z);
void				init_points(t_fdf *data, t_point p1, t_point p2);
int					prepare_points(t_fdf *data, t_point *p1, t_point *p2);
void				bresenham(t_fdf *data, t_point p1, t_point p2);
int					colors(t_fdf *data, t_point p1, t_point p2);
void				my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
unsigned int		ft_abs(int x);
int					numlength(unsigned long n, int base);
unsigned int		ft_atoi_base(const char *str);
void				ft_free_split(char **split);
void				free_z_matrix(t_fdf *data);

#endif