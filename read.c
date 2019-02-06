/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:52:41 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/06 18:23:19 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_line(int fd, char **av)
{
	int		i;
	char	*line;
	int		nbline;
	int		ret;

	i = 0;
	nbline = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		nbline++;
		if (line)
			free(line);
	}
	close(fd);
	return (nbline);
}

int		*convert(int **tab, int j, char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		tab[j][i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	tab[j][i] = -2147483648;
	free(split);
	return (tab[j]);
}

int		**read_line(int fd, t_fdf d)
{
	char	**split;
	char	*line;
	int		j;

	j = 0;
	if (!(d.tab = (int **)malloc(sizeof(int *) * d.nbline)))
		return (0);
	while (get_next_line(fd, &line))
	{
		if (valid_char(line) == 0)
			error("Unvalid char!");
		split = ft_strsplit(line, ' ');
		if (!(d.tab[j] = (int *)malloc(sizeof(int) * ft_strlen(line) + 1)))
			return (0);
		d.tab[j] = convert(d.tab, j, split);
		free(line);
		j++;
	}
	return (d.tab);
}

int		count_col(int **tab)
{
	int x;

	x = 0;
	while (tab[0][x] != -2147483648)
		x++;
	return (x);
}

t_fdf	read_file(char **av)
{
	int		fd;
	t_fdf	d;

	if (valid_file(av[1]) == 0)
		error("Unvalid file!");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("Error");
	if ((d.nbline = count_line(fd, av)) <= 0)
		error("Nothing into the file!");
	if (!(d.tab = read_line(fd, d)))
		error("Can't read this file!");
	d.nbcol = count_col(d.tab);
	close(fd);
	return (d);
}
