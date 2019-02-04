/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:02:45 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/04 17:56:32 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	ft_putnbr(key);
	ft_putchar('\n');
	clear_img(ptr);
	if (key == 49)
		ptr->color += 1;
	if (key == 35 || key == 34)
		(key == 35) ? (ptr->choose = 1) : (ptr->choose = 2);
	if (key == 123 || key == 124)
		(key == 123) ? (ptr->movx -= 5) : (ptr->movx += 5);
	if (key == 125 || key == 126)
		(key == 125) ? (ptr->movy += 5) : (ptr->movy -= 5);
	if (key == 69 || key == 78)
		(key == 69) ? (ptr->zoom += 1) : (ptr->zoom -= 1);
	if (key == 4 || key == 11)
		(key == 4) ? (ptr->z += 1) : (ptr->z -= 1);
	draw(ptr);
	deco(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	ft_put_info(ptr);
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit (0);
	}
	return (0);
}

void	mlx(t_fdf *ptr)
{
	ptr->z = 20;
	ptr->choose = 1;
	ptr->movy = H/2 - (ptr->nbline / 2);
	ptr->movx = W/2;
	ptr->zoom = 10;
	ptr->color = 0xFF;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, H, W, "FdF");
	ptr->img = mlx_new_image(ptr->mlx, W, H);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &ptr->bpp, &ptr->size_l, &ptr->endian);
	deco(ptr);
	draw(ptr);
	mlx_hook(ptr->win, 2, 0, deal_key, ptr);
	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	ft_put_info(ptr);
	mlx_loop(ptr->mlx);
}

int		main(int ac, char **av)
{
	t_fdf ptr;

	if (ac != 2)
		error("usage : fdf maptest");
	ptr = read_file(av);
	mlx(&ptr);
	return(0);
}
