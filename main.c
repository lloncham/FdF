/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:02:45 by lloncham          #+#    #+#             */
/*   Updated: 2019/01/25 18:37:40 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_hook(int button, int x, int y, t_fdf *ptr)
{
	if (button == 1)
	{
		ptr->xiso[0] = x;
		ptr->yiso[0] = y;
	}
	if (button == 2)
	{
		ptr->xiso[1] = x;
		ptr->yiso[1] = y;
		draw(ptr);
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

int		deal_key(int key, t_fdf *ptr)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 123)
	{
		clear_img(ptr);
		ptr->movx -= 1;
		draw_line(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (key == 124)
	{
		clear_img(ptr);
		ptr->movx += 1;
		draw_line(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (key == 69)
	{
		clear_img(ptr);
		ptr->zoom += 1;
		draw_line(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (key == 78)
	{
		clear_img(ptr);
		ptr->zoom -= 1;
		draw_line(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}	
	if (key == 126)
	{
		clear_img(ptr);
		ptr->z = ptr->z + 1;
		draw_line(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (key == 125)
	{
		clear_img(ptr);
		ptr->z = ptr->z - 1;
		draw_line(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit (0);
	}
	return (0);
}

void	mlx(t_fdf *ptr)
{
	ptr->movy = 50;
	ptr->movx = 50;
	ptr->z = 20;
	ptr->zoom = 10;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, H, W, "FdF");
	ptr->img = mlx_new_image(ptr->mlx, W, H);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &ptr->bpp, &ptr->size_l, &ptr->endian);
	draw_line(ptr);
//	mlx_key_hook(ptr->win, deal_key, ptr);
	mlx_hook(ptr->win, 2, 0, deal_key, ptr);
	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	mlx_loop(ptr->mlx);
}

int main(int ac, char **av)
{
	t_fdf ptr;

	if (ac != 2)
		error("usage : fdf maptest");
	ptr = read_file(av);
	mlx(&ptr);
	return(0);
}
