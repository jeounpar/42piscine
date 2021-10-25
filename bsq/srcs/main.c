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

#include "../includes/bsq.h"
#include <stdio.h>

void	make_route(char **arr, int x, int y)
{
	int	up;
	int	up_left;
	int	left;

	up = arr[y - 1][x];
	up_left = arr[y - 1][x - 1];
	left = arr[y][x - 1];
	if (up <= left && up <= up_left)
		arr[y][x] = up + 1;
	if (up_left <= up && up_left <= left)
		arr[y][x] = up_left + 1;
	if (left <= up && left <= up_left)
		arr[y][x] = left + 1;
}

void	ft_make_answer_arr(char **arr, t_info map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_info.line)
	{
		x = 0;
		while (arr[y][x] != '\0')
		{
			if (arr[y][x] == 1)
				arr[y][x] = map_info.obstacle;
			else if (arr[y][x] != map_info.filled)
				arr[y][x] = map_info.empty;
			x++;
		}
		y++;
	}
}

void	ft_find_biggest(char **arr, t_square square, t_info map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_info.line)
	{
		x = 0;
		while (arr[y][x] != '\0')
		{
			if (square.max_size < arr[y][x])
			{
				square.max_size = arr[y][x];
				square.x_pos = x;
				square.y_pos = y;
			}
			x++;
		}
		y++;
	}
	y = square.y_pos - (square.max_size - 2);
	while (y <= square.y_pos)
	{
		x = square.x_pos - (square.max_size -2);
		while (x <= square.x_pos)
		{
			arr[y][x] = map_info.filled;
			x++;
		}
		y++;
	}
	ft_make_answer_arr(arr, map_info);
}

void	print(char **arr, t_info map_info)
{
	int	i = 0;
	int	j = 0;
	printf("!!!!!!!!!!!!!!!!!!!!!!!\n");
	while (i < map_info.line)
	{
		j = 0;
		while (j < map_info.row_size)
		{
			printf("%d ", arr[i][j]);
			j++;
		}	
		printf("\n");
		i++;
	}
}
void	ft_find_square(char **arr, t_info map_info)
{
	int			x;
	int			y;
	t_square	square;

	square = (t_square){1, 0, 0};
	y = 1;
	print(arr, map_info);
	while (y < map_info.line)
	{
		x = 1;
		while (arr[y][x] != '\0')
		{	
			if (arr[y][x] != 1)
				make_route(arr, x, y);
			x++;
		}
		y++;
	}
	print(arr, map_info);
	ft_find_biggest(arr, square, map_info);
	print(arr, map_info);
	// y = 0;
}

void	first_line(t_map **arr, char *filename, int idx)
{
	int		len;
	char	*line_data;

	len = firstline_length(filename);
	line_data = read_firstline(filename, len);
	arr[idx] = init_map(line_data);
	arr[idx]->info.row_size = row_size(filename, arr[idx]->info.line);
}

int main(int argc, char **argv)
{
	t_map	**maps;
	char	*filename;
	int		i;
	
	i = 0;
	if (argc < 2)
	{

	}
	else
		maps = (t_map **)malloc((argc - 1) * sizeof(t_map *));
	while (argc >= 2 && i < argc - 1)
	{
		filename = argv[i + 1];
		first_line(maps, filename, i);
		if (maps[i]->info.row_size == -1)
			ft_putstr("map error\n");
		maps[i]->map = map_data(filename, maps[i]);

		ft_find_square(maps[i]->map, maps[i]->info);

		for (int x = 0; x < maps[i]->info.line; x++)
			printf("%s\n",maps[i]->map[x]);

		i++;
	}
	return (0);
}
