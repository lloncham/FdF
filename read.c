/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:52:41 by lloncham          #+#    #+#             */
/*   Updated: 2019/01/30 15:36:35 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		malloc_r(int **tab, char **split, int nbline)
{
	if (!(tab = (int **)malloc(sizeof(int *) * nbline + 1)))
		return (0);
	if (!(split = (char **)malloc(sizeof(char*) * nbline + 1)))
		return (0);
	return (1);
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
	if (malloc_r(tab, split, nbline) == 0)
		return (0);
	while (get_next_line(fd, &line))
	{	
		if (valid_char(line) == 0)
			error("not valid char");
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
		tab[j][i] = -2147483648;
		j++;
	}
	return (tab);
}

t_fdf	read_file(char **av)
{
	int fd;
	t_fdf d;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("error");
	d.nbline = count_line(fd, av);
	if (!(d.tab = read_line(fd, d.nbline)))
		error("pb de read");
	close(fd);
	return(d);
}
