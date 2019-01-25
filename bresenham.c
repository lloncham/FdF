#include "fdf.h"

void	draw(t_fdf *d)
{
	int dx,dy,i,xinc,yinc,cumul,x,y;
	x = d->xiso[0];
	y = d->yiso[0];
	dx = d->xiso[1] - d->xiso[0];
	dy = d->yiso[1] - d->yiso[0];
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	ft_put_pixel(d, y, x, 0xFF7F7F);
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
			ft_put_pixel(d, y, x, 0xFF7F7F);
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
			ft_put_pixel(d, y, x, 0xFF7F7F);
		}
	}
}

void	draw_line(t_fdf *d)
{
	int x;
	int y;

	y = 0;
	ft_putchar('\n');
	ft_putnbr(d->nbline);
	ft_putchar('\n');
	while (y < d->nbline - 1)
	{
		x = 1;
		while (x < 19)
		{
			d->y[0] = y * d->zoom + (d->tab[y][x] * d->z) + d->movy;
			d->y[1] = y * d->zoom + (d->tab[y][x - 1] * d->z) + d->movy;
			d->x[0] = x * d->zoom + (d->tab[y][x] * d->z) + d->movx;
			d->x[1] = (x - 1) * d->zoom + (d->tab[y][x - 1] * d->z) + d->movx;
			d->yiso[0] = d->x[0] + d->y[0]/2;
			d->xiso[0] = d->x[0] - d->y[0];
			d->yiso[1] = d->x[1] + d->y[1]/2;
			d->xiso[1] = d->x[1] - d->y[1];
			draw(d);
			d->y[1] = (y + 1) * d->zoom + (d->tab[y + 1][x] * d->z) + d->movy;
			d->x[1] = x * d->zoom + (d->tab[y + 1][x] * d->z) + d->movx;
			d->yiso[1] = d->x[1] + d->y[1]/2;
			d->xiso[1] = d->x[1] - d->y[1];
			draw(d);
			x++;
		}
		y++;
	}
}
