/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:45:33 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/07 14:59:24 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define H 1200
# define W 2500 

typedef struct		s_fdf
{
	int				choose;
	int				movy;
	int				movx;
	int				z;
	int				zoom;
	int				*mlx;
	int				*img_data;
	int				*win;
	int				*img;
	int				x[2];
	int				y[2];
	int				color;
	int				nbline;
	int				nbcol;
	int				alt;
	int				**tab;
}					t_fdf;

typedef	struct		s_bre
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				cumul;
}					t_bre;

void				free_tab(t_fdf *d);
int					valid_file(char *str);
void				ft_put_info(t_fdf *d);
void				deco(t_fdf *d);
void				ft_put_pixel(t_fdf *p, int x, int y, int color);
void				draw_line(t_fdf *d);
void				draw(t_fdf *d);
int					deal_key(int key, t_fdf *ptr);
int					mouse_hook(int button, int x, int y, t_fdf *ptr);
void				error(char *str);
t_fdf				read_file(char **av);
int					valid_char(char *str);
int					clear_img(t_fdf *ptr);

#endif
