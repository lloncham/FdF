/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:52:32 by lloncham          #+#    #+#             */
/*   Updated: 2019/01/30 15:07:08 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}
