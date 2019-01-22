#ifndef FDF_H
# define FDF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"

# define H 1000
# define W 1000
# define ABS(Value) (Value < 0 ? -(Value): Value)

typedef struct		s_fdf
{
	int *mlx;
	int *win;
	int *img;
	int	x[2];
	int y[2];
	int nbline;
}					t_fdf;

void	draw(t_fdf *d);
int		deal_key(int key, t_fdf *ptr);
int		mouse_hook(int button, int x, int y, t_fdf *ptr);
int		count_line(int fd, char **av);
int		**read_line(int fd, int nbline);
int		count_words(char **split);
void	error(void);
int		read_file(char **av);
int		valid_char(char *str);

#endif
