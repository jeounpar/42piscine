/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:59:54 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/24 19:11:29 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char	**map_data(char *filename, int line, int row_size)
{
	int		fd;
	int		i;
	int		j;
	int		cnt;
	char	**arr;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		pr_error();
	arr = (char **)malloc(line * sizeof(char *));
	i = 0;
	while (i < line)
	{
		arr[i] = (char *)malloc((row_size + 1) * sizeof(char));
		i++;
	}
	while (read(fd, &c, 1))
		if (c == '\n')
			break;
	while (read(fd, &c, 1))
	{
		ft_putchar(c);
	}
	
	close(fd);
	return (arr);
}

// t_map	*make_map(char *filename, int cnt)
// {
// 	t_map	*map;
// 	char	**str;

// 	map = malloc(sizeof(t_map));
// 	if (map == NULL)
// 		return (NULL);
// 	map->row = cnt;
// }