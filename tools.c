/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:10:13 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/05 12:31:56 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' &&
				str[i] != '+' && str[i] != '\n' && str[i] != '\0')
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
		p->img_data[y * W + x] = color + 0x79E0 - 50;
	if (p->alt > 0)
		p->img_data[y * W + x] = color + 0x79E0;
}
