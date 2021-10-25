/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:18:33 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/24 19:18:34 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	first_line(t_map **arr, char *filename, int idx)
{
	int		len;
	char	*line_data;

	len = firstline_length(filename);
	line_data = read_firstline(filename, len);
	arr[idx] = init_map(line_data);
	arr[idx]->row_size = row_size(filename, arr[idx]->line);
}

int main(int argc, char **argv)
{
	char 	str[1000];
	t_map	**maps;
	char	*filename;
	int		i;
	
	i = 0;
	if (argc < 2)
		read(0, str, 1000);
	maps = (t_map **)malloc((argc - 1) * sizeof(t_map *));
	while (argc >= 2 && i < argc - 1)
	{
		filename = argv[i + 1];
		first_line(maps, filename, i);
		if (maps[i]->row_size == -1)
			ft_putstr("map error\n");
		maps[i]->map = map_data(filename, maps[i]);

		printf("row_size = %d\n", maps[i]->row_size);
		printf("line = %d\n", maps[i]->line);
		printf("empty : %c\n", maps[i]->empty);
		printf("obstacle : %c\n", maps[i]->obstacle);
		printf("filled : %c\n", maps[i]->filled);
		for (int x = 0; x < maps[i]->line; x++)
			printf("%s\n",maps[i]->map[x]);

		i++;
	}
	return (0);
}
