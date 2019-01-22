#include "fdf.h"

void	error()
{
	ft_putendl("error");
	exit(0);
}

int		count_line(int fd, char **av)
{
	int		i;
	char	*line;
	int		nbline;

	i = 0;
	nbline = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		nbline++;
		if (line)
			free(line);
	}
	close(fd);
	return (nbline);
}

int		count_words(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		**read_line(int fd, int nbline)
{
	char	**split;
	int		**tab;
	char	*line;
	int		j;
	int		i;
	
	j = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nbline + 1)))
		return (0);
	if (!(split = (char **)malloc(sizeof(char*) * nbline + 1)))
		return (0);
	while (get_next_line(fd, &line))
	{	
		if (valid_char(line) == 0)
			return (0);
		split = ft_strsplit(line, ' ');
		if (!(tab[j] = (int *)malloc(sizeof(int) * count_words(split) + 1)))
			return (0);
		i = 0;
		while (split[i])
		{
			tab[j][i] = ft_atoi(split[i]);
			free(split[i]);
			i++;
		}
		j++;
	}
	return (tab);
}

int		read_file(char **av)
{
	int fd;
	int	**tab;
	t_fdf d;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		error();
	d.nbline = count_line(fd, av);
	ft_putnbr(d.nbline);
	if (!(tab = read_line(fd, d.nbline)))
		error();
	close(fd);
	return(0);
}
