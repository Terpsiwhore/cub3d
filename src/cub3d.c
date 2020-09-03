/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:04:23 by kcorazon          #+#    #+#             */
/*   Updated: 2020/08/24 14:04:25 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_parser.h"

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void 			print_square(t_data *img, int y, int x, int size, int color)
{
	int x_start;

	y *= size;
	x *= size;
	x_start = x;
	while (++y % size != 0)
	{
		x = x_start;
		while (++x % size != 0)
			my_mlx_pixel_put(img, x - 1, y - 1, color);
		my_mlx_pixel_put(img, x - 1, y - 1, color);
	}
}

void 			create_image(t_data *img, t_map map)
{
	int y;
	int x;

	y = 0;
	while (map.row[y] != 0 && y < 50)
	{
		x = 0;
		while (map.row[y][x] != 0 && x < 50)
		{
			if (map.row[y][x] == '1')
				print_square(img, y, x, 10, 0xFFFFFF);
			++x;
		}
		++y;
	}
}

void 			create_win(t_map map)
{
	void    *mlx;
	void    *mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	create_image(&img, map);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int             main(int argc, char **argv)
{
	t_map	map;


	if (argc == 2)
	{
		ft_parser(argv[1], &map);
		create_win(map);
	}
}