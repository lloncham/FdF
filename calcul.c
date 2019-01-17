#include "fdf.h"

int		draw(t_fdf *d)
{
	float dx;
	float dy;
	float a;
	float x;
	float y;

	x = d->x[0];
	y = d->y[0];
	dx = d->x[1] - d->x[0];
	dy = d->y[1] - d->y[0];
	a = ABS(dy)/ABS(dx);
	if (dx > dy)
	{
		while (x != d->x[1])
		{
			mlx_pixel_put(d->mlx, d->win, y, x, 0xFFFFFF);
			(dx > 0) ? x++ : x--;
			(dy > 0) ? (y += a) : (y -= a);
		}
	}
	else
	{
		while (y != d->y[1])
		{
			mlx_pixel_put(d->mlx, d->win, y, x, 0xFFFFFF);
			(dy > 0) ? y++ : y--;
			(dx > 0) ? (x += a) : (x -= a);
		}
	}
	return (0);
}
