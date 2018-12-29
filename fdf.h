#ifndef FDF_H
# define FDF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "./libft/libft.h"
#include <stdlib.h>

char	chardup(char c);
char	*read_file(int fd, char *str);
int		line_nb(char *str);
int		colomn(char *str);
int		size_str(int fd, char *buff);
char	ft_chardup(char c);
int		valid_char(char c);
#endif
