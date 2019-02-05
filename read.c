/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:52:41 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/05 12:46:39 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int		i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		**read_line(int fd, t_fdf d)
{
	char	**split;
	char	*line;
	int		j;
	int		i;

	j = 0;
	if (!(d.tab = (int **)malloc(sizeof(int *) * d.nbline)))
		return (0);
	while (get_next_line(fd, &line))
	{
		if (valid_char(line) == 0)
			error("not valid char");
		split = ft_strsplit(line, ' ');
		if (!(d.tab[j] = (int *)malloc(sizeof(int) * count_words(split) + 1)))
			return (0);
		i = 0;
		while (split[i])
		{
			d.tab[j][i] = ft_atoi(split[i]);
			if (split)
				free(split[i]);
			i++;
		}
		if (line)
			free(line);
		free(split);
		d.tab[j][i] = -2147483648;
		j++;
	}
	return (d.tab);
}

t_fdf	read_file(char **av)
{
	int		fd;
	t_fdf	d;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("error");
	d.nbline = count_line(fd, av);
	if (!(d.tab = read_line(fd, d)))
		error("pb de read");
	close(fd);
	return (d);
}
