/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:55:34 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/07 14:59:01 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		valid_file(char *str)
{
	char	*s;
	int		i;
	int		j;

	s = ".fdf";
	j = ft_strlen(s);
	i = ft_strlen(str);
	while (j != 0)
	{
		if (str[i--] != s[j--])
			return (0);
	}
	return (1);
}

int		valid_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			while (str[i] != ' ')
				i++;
		}
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-'
				&& str[i] != '+' && str[i] != '\n' && str[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		clear_img(t_fdf *ptr)
{
	bzero(ptr->img_data, W * H * 4);
	return (0);
}

void	ft_put_pixel(t_fdf *p, int y, int x, int color)
{
	if (x < 0 || y < 0 || x >= W || y >= H)
		return ;
	if (p->alt == 0)
		p->img_data[y * W + x] = color + 0xBDF7;
	if (p->alt < 0)
		p->img_data[y * W + x] = color + 0x79E0 - 100;
	if (p->alt > 0 && p->alt <= 3)
		p->img_data[y * W + x] = color + 0x79E0;
	if (p->alt > 3)
		p->img_data[y * W + x] = color + 0x79E0 + 100;
}
