/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:44:47 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/25 00:44:48 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	read_firstline(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("map error\n");
		exit(1);
	}

	close(fd);	
}

t_input *get_mapdata(char *str)
{
	t_input	*arr;
	int		line;
	int		idx;

	arr = malloc(sizeof(t_input));
	if (arr == NULL)
		return (NULL);
	line = ft_atoi(str, &idx);
	arr->line = line;
	arr->empty = str[idx];
	arr->obstacle = str[idx + 1];
	arr->filled = str[idx + 1];
	return (arr);	
}