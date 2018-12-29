#include "./libft/libft.h"

int		valid_char(char c)
{
	if (!ft_isdigit(c) && c != ' ' && c != '-' && c != '\n')
			return (0);
	return (1);
}
