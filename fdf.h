/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:45:33 by lloncham          #+#    #+#             */
/*   Updated: 2019/01/25 18:22:16 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"

# define H 500 
# define W 500
# define ABS(Value) (Value < 0 ? -(Value): Value)

typedef struct		s_fdf
{
	int	movy;
	int movx;
	int z;
	int zoom;
	int bpp;
	int size_l;
	int endian;
	int *mlx;
	int *img_data;
	int *win;
	int *img;
	int	x[2];
	int y[2];
	int xiso[2];
	int yiso[2];
	int nbline;
	int **tab;
}					t_fdf;

void	ft_put_pixel(t_fdf *p, int x, int y, int color);
void	draw_line(t_fdf *d);
void	draw(t_fdf *d);
int		deal_key(int key, t_fdf *ptr);
int		mouse_hook(int button, int x, int y, t_fdf *ptr);
int		count_line(int fd, char **av);
int		**read_line(int fd, int nbline);
int		count_words(char **split);
void	error(char *str);
t_fdf	read_file(char **av);
int		valid_char(char *str);

#endif
