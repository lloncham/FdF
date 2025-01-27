/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:02:45 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/07 14:58:30 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
		draw_line(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	return (0);
}

int		deal_key(int key, t_fdf *ptr)
{
	clear_img(ptr);
	if (key == 49)
		ptr->color += 10;
	if (key == 35)
		ptr->choose = 1;
	if (key == 34)
		ptr->choose = 2;
	if (key == 123 || key == 124)
		(key == 123) ? (ptr->movx -= 30) : (ptr->movx += 30);
	if (key == 125 || key == 126)
		(key == 125) ? (ptr->movy += 5) : (ptr->movy -= 5);
	if (key == 69 || key == 78)
		(key == 69) ? (ptr->zoom += 1) : (ptr->zoom -= 1);
	if (key == 4 || key == 11)
		(key == 4) ? (ptr->z -= 1) : (ptr->z += 1);
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		free_tab(ptr);
		exit(0);
	}
	draw(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	ft_put_info(ptr);
	return (0);
}

void	mlx(t_fdf *ptr)
{
	int bpp;
	int endian;
	int size_l;

	ptr->z = 0;
	ptr->choose = 1;
	if (ptr->nbline >= ptr->nbcol)
		ptr->zoom = ((H / 3) / ptr->nbline);
	else
		ptr->zoom = ((W / 3) / ptr->nbcol);
	ptr->movy = H / 2 - ((ptr->nbline / 2) * ptr->zoom);
	ptr->movx = W / 2 - ((ptr->nbcol / 2) * ptr->zoom);
	ptr->color = 0xFF;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, W, H, "FdF");
	ptr->img = mlx_new_image(ptr->mlx, W, H);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &bpp, &size_l, &endian);
	draw(ptr);
	mlx_hook(ptr->win, 2, 0, deal_key, ptr);
	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	ft_put_info(ptr);
	mlx_loop(ptr->mlx);
}

void	free_tab(t_fdf *f)
{
	int i;

	i = 0;
	if (!f->tab)
		return ;
	while (++i < f->nbline)
		free(f->tab[i]);
	free(f->tab);
}

int		main(int ac, char **av)
{
	t_fdf ptr;

	if (ac != 2)
		error("usage : [./fdf] [maptest.fdf]");
	ptr = read_file(av);
	mlx(&ptr);
	return (0);
}
