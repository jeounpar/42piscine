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

int main(int argc, char **argv)
{
	char 	str[1000];
	t_map	**map_arr;
	int		len;
	char 	*line_data;
	char	*filename;
	int		i;
	
	i = 0;
	if (argc < 2)
		read(0, str, 1000);
	else if (argc >= 2 && i < argc - 1)
	{
		map_arr = (t_map **)malloc((argc - 1) * sizeof(t_map *));
		filename = argv[i + 1];
		len = firstline_length(filename);
		line_data = read_firstline(filename, len);
		map_arr[i] = init_map(line_data);
		map_arr[i]->row_size = row_size(filename, map_arr[i]->line);
		if (map_arr[i]->row_size == -1)
			ft_putstr("map error\n");
		printf("row = %d\n", map_arr[i]->row_size);
		printf("line = %d\n", map_arr[i]->line);
		printf("empty : %c\n", map_arr[i]->empty);
		printf("obstacle : %c\n", map_arr[i]->obstacle);
		printf("filled : %c\n", map_arr[i]->filled);
		map_arr[i]->map = map_data(filename, map_arr[i]->line, map_arr[i]->row_size);
		// for (int k = 0; k < map_arr[k]->line; k++)
		// 	printf("%s\n",map_arr[i]->map[k]);
		// i++;
	}
	return (0);
}