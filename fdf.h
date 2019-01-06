#ifndef FDF_H
# define FDF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"

int		deal_key(int key, void *param);
//int		**read_line(int fd, int nb_line);
//int		count_line(int fd);
//int		count_words(char **split);
//void	error(void);
int		valid_char(char *str);

#endif
