#include "fdf.h"

#include <stdio.h>

int		mouse_hook(int button, int x, int y, t_fdf *ptr)
{
	printf("BUTTON = %d - Y = %d - X = %d\n", button, y, x);
	if (button == 1)
	{
		ptr->x[0] = x;
		ptr->y[0] = y;
	}
	printf("Y1 = %d - X1 = %d\n", ptr->y[0], ptr->x[0]);
	if (button == 2)
	{
		ptr->x[1] = x;
		ptr->y[1] = y;
		draw(ptr);
	}
	printf("Y2 = %d - X2 = %d\n", ptr->y[1], ptr->x[1]);
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

int main()
{
	t_fdf ptr;

	mlx(&ptr);
	return(0);
}
