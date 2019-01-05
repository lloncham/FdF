#include "./libft/libft.h"

int		valid_char(char *s)
{
	int i;

	i = 0;
	while (s[i++])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+' && s[i] == '\n')
			return (0);
	}
	return (1);
}
