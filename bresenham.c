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
	mlx_pixel_put(d->mlx, d->win, x, y, 0x0000FF);
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
			mlx_pixel_put(d->mlx, d->win, x, y, 0x0000FF);
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
			mlx_pixel_put(d->mlx, d->win, x, y, 0x0000FF);
		}
	}
}
