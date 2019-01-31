/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:02:45 by lloncham          #+#    #+#             */
/*   Updated: 2019/01/30 16:26:40 by lloncham         ###   ########.fr       */
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

int		clear_img(t_fdf *ptr)
{
	bzero(ptr->img_data, W * H * 4);
	return (0);
}

void	ft_put_pixel(t_fdf *p, int y, int x, int color)
{
	if (x < 0 || y < 0 || x >= W || y >= H)
		return ;
	p->img_data[y * W + x] = color;	
}

void	ft_put_info(t_fdf *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 20, 20, 0xFFFFFF, "MENU");
	mlx_string_put(ptr->mlx, ptr->win, 20, 60, 0xFFFFFF, "Zoom : + / -");
	mlx_string_put(ptr->mlx, ptr->win, 20, 80, 0xFFFFFF, "Move : -> / <- / .. / .. ");
	mlx_string_put(ptr->mlx, ptr->win, 20, 100, 0xFFFFFF, "Altitude : h / b");
}

int		deal_key(int key, t_fdf *ptr)
{
	ft_putnbr(key);
	ft_putchar('\n');
	clear_img(ptr);
	if (key == 35 || key == 34)
	{
		(key == 35) ? (ptr->choose = 1) : (ptr->choose = 2);
		(key == 35) ? ptr->z : (ptr->z = -ptr->z);
	}
	if (key == 123 || key == 124)
		(key == 123) ? (ptr->movx -= 5) : (ptr->movx += 5);
	if (key == 125 || key == 126)
		(key == 125) ? (ptr->movy += 5) : (ptr->movy -= 5);
	if (key == 69 || key == 78)
		(key == 69) ? (ptr->zoom += 1) : (ptr->zoom -= 1);
	if (key == 4 || key == 11)
		(key == 4) ? (ptr->z += 1) : (ptr->z -= 1);
	draw(ptr);
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
	ptr->movy = 0;
	ptr->movx = 0;
	ptr->zoom = 10;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, H, W, "FdF");
	ptr->img = mlx_new_image(ptr->mlx, W, H);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &ptr->bpp, &ptr->size_l, &ptr->endian);
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
