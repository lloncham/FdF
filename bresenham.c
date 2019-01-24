#include "fdf.h"

void	draw(t_fdf *d)
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
	mlx_pixel_put(d->mlx, d->win, x, y, 0x00FF7F7F);
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
		mlx_pixel_put(d->mlx, d->win, x, y, 0x00FF7F7F);
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
			mlx_pixel_put(d->mlx, d->win, x, y, 0xFFCB60);
		}
	}
}

void	draw_line(t_fdf *d)
{
	int x;
	int y;

	y = 0;
	while (y < d->nbline - 1)
	{
		x = 1;
		while (d->tab[y][x] != -2147483648)
		{
			d->y[0] = y * 10 + (d->tab[y][x] * 10) + 10;
			d->y[1] = y * 10 + (d->tab[y][x - 1] * 10) + 10;
			d->x[0] = x * 10 + (d->tab[y][x] * 10) + 10;
			d->x[1] = (x - 1) * 10 + (d->tab[y][x - 1] * 10) + 10;
			draw(d);
			d->y[1] = (y + 1) * 10 + (d->tab[y + 1][x] * 10) + 10;
			d->x[1] = x * 10 + (d->tab[y + 1][x] * 10) + 10;
			draw(d);
			x++;
		}
		y++;
	}
}
