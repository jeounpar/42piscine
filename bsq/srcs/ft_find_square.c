/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:29:08 by ibae              #+#    #+#             */
/*   Updated: 2021/10/28 00:43:43 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_make_intarr(char **arr, int **intarr, t_info map_info);

void	make_route(int **intarr, int x, int y)
{
	int	up;
	int	up_left;
	int	left;

	up = intarr[y - 1][x];
	up_left = intarr[y - 1][x - 1];
	left = intarr[y][x - 1];
	if (up <= left && up <= up_left)
		intarr[y][x] = up + 1;
	if (up_left <= up && up_left <= left)
		intarr[y][x] = up_left + 1;
	if (left <= up && left <= up_left)
		intarr[y][x] = left + 1;
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

void	ft_find_biggest(char **arr, int **intarr, t_square s, t_info info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info.line)
	{
		x = 0;
		while (x < info.row_size)
		{
			if (s.max_size < intarr[y][x])
			{
				s.max_size = intarr[y][x];
				s.x_pos = x;
				s.y_pos = y;
			}
			x++;
		}
		y++;
	}
	ft_make_filled(arr, s, info);
	int_malloc_free(intarr, info.line);
}

void	make_first_rowcol(char **arr, int **intarr, t_info map_info)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_info.row_size)
	{
		if (arr[0][x] == map_info.obstacle)
			intarr[0][x] = 1;
		else if (arr[0][x] == map_info.empty)
			intarr[0][x] = 2;
		x++;
	}
	y = 1;
	while (y < map_info.line)
	{
		if (arr[y][0] == map_info.obstacle)
			intarr[y][0] = 1;
		else if (arr[y][0] == map_info.empty)
			intarr[y][0] = 2;
		y++;
	}
}

void	ft_find_square(char **arr, t_info map_info)
{
	int			y;
	int			**intarr;
	t_square	square;

	square = (t_square){1, 0, 0};
	intarr = (int **)malloc(sizeof(int *) * map_info.line);
	if (intarr == NULL)
		exit (1);
	y = -1;
	while (++y < map_info.line)
	{
		intarr[y] = malloc(sizeof(int) * map_info.row_size);
		if (intarr[y] == NULL)
			exit (1);
	}
	make_first_rowcol(arr, intarr, map_info);
	ft_make_intarr(arr, intarr, map_info);
	ft_find_biggest(arr, intarr, square, map_info);
}
