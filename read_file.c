#include "fdf.h"

char	*read_file(int fd, char *str)
{
	char	buff[1];
	int		ret;
	int		i;
	while ((ret = read(fd, buff, 1)) > 0)
	{
		if (ret == -1)
			return (0);
		if (valid_char(buff[0]) == 0)
			return (0);
		str[i++] = buff[0];
	}
	str[i] = '\0';
	return (str);
}

int		line_nb(char *str)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

int		colomn_nb(char *str)
{
	int i;
	int colomn;

	i = 0;
	colomn = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '-' || str[i] == ' ')
			i++;
		if (ft_isdigit(str[i]))
		{
			colomn++;
			i++;
		}
	}
	return (colomn);
}

int		get_nbr(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= 0 && str[i] <= 9)
	{
		nbr = ft_atoi(str[i]);
		i++;
	}
	return (nbr);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*str;

	ac = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
//changer la taille!!
	str = (char*)malloc(sizeof(char) * 50);
	ft_putstr(read_file(fd, str));
	close(fd);
	fd = open(av[1], O_RDONLY);
	str = (char*)malloc(sizeof(char) * 50);
	ft_putnbr(colomn_nb(read_file(fd, str)));
	close(fd);
	fd = open(av[1], O_RDONLY);
	str = (char*)malloc(sizeof(char) * 50);
	ft_putnbr(line_nb(read_file(fd, str)));
	return (0);
}
