#include "fdf.h"

int		deal_key(int key, void *param)
{
	(void)param;
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit (0);
	return (0);
}

int		main()
{
	int		*mlx;
	int		*win;
	int		*img_ptr;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "titre");
	img_ptr = mlx_new_image(mlx, 500, 500);
	mlx_pixel_put(mlx, win, 250, 250, 0xFFFFFF);
	mlx_key_hook(win, deal_key, (void*)0);
//	mlx_put_image_to_window(mlx, win, img_ptr, 0, 0);
	mlx_loop(mlx);
}
