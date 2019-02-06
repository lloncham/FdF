/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:43:46 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/06 16:09:35 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_h(t_fdf *d, int x, int y)
{
	d->y[0] = ((x * d->zoom + d->tab[y][x] * d->z)
		+ (y * d->zoom + d->tab[y][x] * d->z) + d->movy) / 2;
	d->x[0] = (x * d->zoom + d->tab[y][x] * d->z)
		- (y * d->zoom + d->tab[y][x] * d->z) + d->movx;
	d->y[1] = (((x - 1) * d->zoom + d->tab[y][x - 1] * d->z)
		+ (y * d->zoom + d->tab[y][x - 1] * d->z) + d->movy) / 2;
	d->x[1] = ((x - 1) * d->zoom + d->tab[y][x - 1] * d->z)
		- (y * d->zoom + d->tab[y][x - 1] * d->z) + d->movx;
	draw_line(d);
}

void	iso(t_fdf *d)
{
	int x;
	int y;
	int tempx[2];
	int tempy[2];

	y = 0;
	while (y < d->nbline - 1)
	{
		x = 1;
		while (x < d->nbcol)
		{
			d->alt = d->tab[y][x];
			iso_h(d, x, y);
			d->y[1] = ((x * d->zoom + d->tab[y + 1][x] * d->z)
				+ ((y + 1) * d->zoom + d->tab[y + 1][x] * d->z) + d->movy) / 2;
			d->x[1] = (x * d->zoom + d->tab[y + 1][x] * d->z)
				- ((y + 1) * d->zoom + d->tab[y + 1][x] * d->z) + d->movx;
			draw_line(d);
			x++;
		}
		y++;
	}
	deco(d);
}

void	para(t_fdf *d)
{
	int x;
	int y;
	int tempx[2];
	int tempy[2];

	y = 0;
	while (y < d->nbline - 1)
	{
		x = 1;
		while (x < d->nbcol)
		{
			d->alt = d->tab[y][x];
			d->y[0] = y * d->zoom + (d->tab[y][x] * d->z) + d->movy;
			d->x[0] = x * d->zoom + (d->tab[y][x] * d->z) + d->movx;
			d->y[1] = y * d->zoom + (d->tab[y][x - 1] * d->z) + d->movy;
			d->x[1] = (x - 1) * d->zoom + (d->tab[y][x - 1] * d->z) + d->movx;
			draw_line(d);
			d->y[1] = (y + 1) * d->zoom + (d->tab[y + 1][x] * d->z) + d->movy;
			d->x[1] = x * d->zoom + (d->tab[y + 1][x] * d->z) + d->movx;
			draw_line(d);
			x++;
		}
		y++;
	}
	deco(d);
}

void	draw(t_fdf *d)
{
	if (d->choose == 2)
		iso(d);
	if (d->choose == 1)
		para(d);
}
