/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:33:51 by ibae              #+#    #+#             */
/*   Updated: 2021/10/28 00:45:19 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	make_route(int	**intarr, int row, int col);

void	ft_make_intarr(char **arr, int **intarr, t_info map_info)
{
	int	x;
	int	y;

	y = 0;
	while (++y < map_info.line)
	{
		x = 0;
		while (++x < map_info.row_size)
		{
			if (arr[y][x] == map_info.obstacle)
				intarr[y][x] = 1;
			else
				make_route(intarr, x, y);
		}
	}
}
