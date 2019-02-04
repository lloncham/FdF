#include "fdf.h"

void	draw_line(t_fdf *d)
{
	int dx,dy,i,xinc,yinc,cumul,x,y;
	x = d->x[0];
	y = d->y[0];
	dx = d->x[1] - d->x[0];
	dy = d->y[1] - d->y[0];
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	ft_put_pixel(d, y, x, d->color);
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 1;
		while (i++ <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			ft_put_pixel(d, y, x, d->color);
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i++ <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			ft_put_pixel(d, y, x, d->color);
		}
	}
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
		while (d->tab[y][x] != -2147483648)
		{
			d->alt = d->tab[y][x];
			d->y[0] = (x - y) * d->zoom - (d->tab[y][x] * d->z) + d->movy;
			d->x[0] = (x + y) * d->zoom - (d->tab[y][x] * d->z) + d->movx;
			d->y[1] = ((x - 1) - y) * d->zoom - (d->tab[y][x - 1] * d->z) + d->movy;
			d->x[1] = ((x - 1) + y) * d->zoom - (d->tab[y][x - 1] * d->z) + d->movx;
			draw_line(d);
			d->y[1] = (x - (y + 1)) * d->zoom - (d->tab[y + 1][x] * d->z) + d->movy;
			d->x[1] = (x + (y + 1)) * d->zoom - (d->tab[y + 1][x] * d->z) + d->movx;
			draw_line(d);
			x++;
		}
		y++;
	}
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
		while (d->tab[y][x] != -2147483648)
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
}

void	draw(t_fdf *d)
{
	if (d->choose == 2)
		iso(d);
	if (d->choose == 1)
		para(d);
}
