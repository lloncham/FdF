#include "fdf.h"

void	error()
{
	ft_putendl("error");
	exit(0);
}

int		count_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line))
		i++;
	return (i);
}

int		count_words(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		**read_line(int fd, int nb_line)
{
	char	**split;
	int		**tab;
	char	*line;
	int		j;
	int		i;
	
	i = 0;
	j = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 50 + 1)))
		return (0);
	if (!(split = (char **)malloc(sizeof(char*) * 50 + 1)))
		return (0);
	while (get_next_line(fd, &line))
	{	
		if (valid_char(line) == 0)
			return (0);
		split = ft_strsplit(line, ' ');
		if (!(tab[j] = (int *)malloc(sizeof(int) * count_words(split) + 1)))
			return (0);
		tab[j][i] = atoi(split[i]);
		i++;
		j++;
	}
	return (tab);
}

int		main(int ac, char **av)
{
	int fd;
	int nb_line;
	int	**tab;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error();
			if ((tab = read_line(fd, nb_line)) == 0)
				error();
		close(fd);
	}
	return (0);
}
