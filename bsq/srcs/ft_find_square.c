/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:29:08 by ibae              #+#    #+#             */
/*   Updated: 2021/10/26 11:17:12 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"

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

void	ft_make_filled(char **arr, t_square square, t_info map_info)
{
	int	x;
	int	y;

	y = square.y_pos - (square.max_size - 2);
	while (y <= square.y_pos)
	{
		x = square.x_pos - (square.max_size - 2);
		while (x <= square.x_pos)
		{
			arr[y][x] = map_info.filled;
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
	ft_make_filled(arr, square, map_info);
	ft_make_answer_arr(arr, map_info);
}

void	ft_find_square(char **arr, t_info map_info)
{
	int			x;
	int			y;
	t_square	square;

	square = (t_square){1, 0, 0};
	y = 1;
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
	ft_find_biggest(arr, square, map_info);
}
