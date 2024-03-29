/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:59:54 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/27 16:34:09 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	**malloc_arr(int line, int row_szie)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(line * sizeof(char *));
	if (arr == NULL)
		exit (1);
	i = 0;
	while (i < line)
	{
		arr[i] = (char *)malloc((row_szie + 1) * sizeof(char));
		if (arr[i] == NULL)
			exit (1);
		i++;
	}
	return (arr);
}

int	putin_char(char **arr, t_map *map, int fd)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (read(fd, &c, 1))
	{
		if (c != '\n')
		{
			if (c == map->info.obstacle)
				arr[i][j] = map->info.obstacle;
			else if (c == map->info.empty)
				arr[i][j] = map->info.empty;
			j++;
		}
		else if (c == '\n')
		{
			arr[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	return (fd);
}

char	**map_data(char *filename, t_map *map)
{
	int		fd;
	char	**arr;

	fd = open(filename, O_RDONLY);
	arr = malloc_arr(map->info.line, map->info.row_size);
	fd = skip_fristline(fd);
	fd = putin_char(arr, map, fd);
	close(fd);
	return (arr);
}
