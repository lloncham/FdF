#include "fdf.h"

#include <stdio.h>

int		mouse_hook(int button, int x, int y, t_fdf *ptr)
{
	if (button == 1)
	{
		ptr->x[0] = x;
		ptr->y[0] = y;
	}
	if (button == 2)
	{
		ptr->x[1] = x;
		ptr->y[1] = y;
		draw(ptr);
	}
	return (0);
}

int		deal_key(int key, t_fdf *ptr)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit (0);
	}
	return (0);
}

void	mlx(t_fdf *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, H, W, "FdF");
	ptr->img = mlx_new_image(ptr->mlx, H, W);
	mlx_pixel_put(ptr->mlx, ptr->win, 250, 250, 0xFFFFFF);
	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	mlx_key_hook(ptr->win, deal_key, ptr);
//	mlx_put_image_to_window(mlx, win, img_ptr, 0, 0);
	mlx_loop(ptr->mlx);
}

int main(int ac, char **av)
{
	t_fdf ptr;

	if (ac != 2)
		error();
	read_file(av);
	mlx(&ptr);
	return(0);
}
