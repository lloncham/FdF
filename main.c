#include "./minilibx_macos/mlx.h"

int		main()
{
	int	*mlx_ptr;
	int	*win_ptr;
	int	*img_ptr;
	int	*img_data;
	int bpp;
	int size_l;
	int endian;
	int count_h;
	int count_w;

	int fd;
	int ret;

	fd = open(argv[1], O_RDONLY)
	while (ret = get_next_line(fd, &line) > 0)
	{
		check_line();
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "titre");
	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	img_data = (int*)mlx_get_data_addr(img_ptr, &bpp, &size_l, &endian);
//	Maintenant, juste un petit exemple: voici une boucle qui va dessiner chaque pixel qui
//	avoir une largeur impaire en blanc et ceux qui ont une largeur paire en noir.
	count_h = -1;
	while (++count_h < 500)
	{
		count_w = - 1 ;
		while (++count_w < 500)
		{
			if (count_w % 2)
//			une couleur à chaque pixel un par un dans l'image,
//			image sera imprimée en une fois à la fin de la boucle.
//			vous travaillez sur une dimension alors que votre fenêtre est (évidemment) à 2 dimensions.
//			au lieu d'avoir les données [hauteur] [largeur] ici, vous aurez cette formule: [hauteur actuelle * largeur maximale + largeur actuelle]
				img_data[count_h * 500 + count_w] = 0xFFFFFF;
			else
				img_data[count_h * 500 + count_w] = 0;
		}
	}
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
