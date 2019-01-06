#include "./libft/libft.h"

int		valid_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+' && str[i] != '\n' && str[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}
