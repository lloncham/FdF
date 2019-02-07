/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deco.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:29:25 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/07 14:58:20 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	deco_up(t_fdf *d)
{
	int y;
	int x;

	y = 0;
	while (y < 40)
	{
		x = 0;
		while (x < W)
		{
			if (y > 38)
				d->img_data[y * W + x] = 0xFFFFFF;
			else
				ft_put_pixel(d, y, x, d->color);
			x++;
		}
		y++;
	}
}

void	deco_down(t_fdf *d)
{
	int x;
	int y;

	y = H - 40;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			if (y < H - 38)
				d->img_data[y * W + x] = 0xFFFFFF;
			else
				ft_put_pixel(d, y, x, d->color);
			x++;
		}
		y++;
	}
}

void	ft_put_info(t_fdf *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, W / 2 - 1.5, 10, 0xFFFFFF, "FDF");
	mlx_string_put(ptr->mlx, ptr->win, 20, 45, 0xFFFFFF, "MENU");
	mlx_string_put(ptr->mlx, ptr->win, 20, 75,
			0xFFFFFF, "Draw line : click left / click right");
	mlx_string_put(ptr->mlx, ptr->win, 20, 95,
			0xFFFFFF, "Move : > / < / ^ / v ");
	mlx_string_put(ptr->mlx, ptr->win, 20, 115, 0xFFFFFF, "Zoom : + / -");
	mlx_string_put(ptr->mlx, ptr->win, 20, 135, 0xFFFFFF, "Altitude : h / b");
	mlx_string_put(ptr->mlx, ptr->win, 20, 155, 0xFFFFFF, "Projection : i / p");
	mlx_string_put(ptr->mlx, ptr->win, 20, 175,
			0xFFFFFF, "Change color : space");
}

void	deco(t_fdf *d)
{
	deco_up(d);
	deco_down(d);
}
