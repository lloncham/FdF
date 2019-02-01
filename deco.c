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
			ft_put_pixel(d, y, x, d->color);
			x++;
		}
		y++;
	}
}

void	deco(t_fdf *d)
{
	deco_up(d);
	deco_down(d);
}
