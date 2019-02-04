/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deco.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:29:25 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/04 16:13:23 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
				ft_put_pixel(d, y, x, 0xFFFFFF);
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
				ft_put_pixel(d, y, x, 0xFFFFFF);
			else
				ft_put_pixel(d, y, x, d->color);
			x++;
		}
		y++;
	}
}

void	ft_put_info(t_fdf *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, W/2 - 1.5, 10, 0xFFFFFF, "FDF");
	mlx_string_put(ptr->mlx, ptr->win, 20, 45, 0xFFFFFF, "MENU");
	mlx_string_put(ptr->mlx, ptr->win, 20, 70, 0xFFFFFF, "Draw line : click left / click right");
	mlx_string_put(ptr->mlx, ptr->win, 20, 90, 0xFFFFFF, "Move : -> / <- / .. / .. ");
	mlx_string_put(ptr->mlx, ptr->win, 20, 110, 0xFFFFFF, "Zoom : + / -");
	mlx_string_put(ptr->mlx, ptr->win, 20, 130, 0xFFFFFF, "Altitude : h / b");
	mlx_string_put(ptr->mlx, ptr->win, 20, 150, 0xFFFFFF, "Projection : i / p");
}

void	deco(t_fdf *d)
{
	deco_up(d);
	deco_down(d);
}
