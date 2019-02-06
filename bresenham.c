/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:17:57 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/06 14:42:03 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bre	init_bre(t_fdf *d)
{
	t_bre	i;

	i.x = d->x[0];
	i.y = d->y[0];
	i.dx = d->x[1] - d->x[0];
	i.dy = d->y[1] - d->y[0];
	i.xinc = (i.dx > 0) ? 1 : -1;
	i.yinc = (i.dy > 0) ? 1 : -1;
	i.dx = abs(i.dx);
	i.dy = abs(i.dy);
	return (i);
}

void	slow_line(t_fdf *d, t_bre b)
{
	int		i;

	b.cumul = b.dx / 2;
	i = 1;
	while (i++ <= b.dx)
	{
		b.x += b.xinc;
		b.cumul += b.dy;
		if (b.cumul >= b.dx)
		{
			b.cumul -= b.dx;
			b.y += b.yinc;
		}
		ft_put_pixel(d, b.y, b.x, d->color);
	}
}

void	fast_line(t_fdf *d, t_bre b)
{
	int		i;

	b.cumul = b.dy / 2;
	i = 1;
	while (i++ <= b.dy)
	{
		b.y += b.yinc;
		b.cumul += b.dx;
		if (b.cumul >= b.dy)
		{
			b.cumul -= b.dy;
			b.x += b.xinc;
		}
		ft_put_pixel(d, b.y, b.x, d->color);
	}
}

void	draw_line(t_fdf *d)
{
	t_bre	b;

	b = init_bre(d);
	ft_put_pixel(d, b.y, b.x, d->color);
	if (b.dx > b.dy)
		slow_line(d, b);
	else
		fast_line(d, b);
}
