/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:29:53 by ibae              #+#    #+#             */
/*   Updated: 2021/10/16 22:31:11 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_print_solution(int **arr, int mx)
{
	int		row;
	int		col;
	char	c;

	row = 1;
	while (row < mx + 1)
	{
		col = 1;
		while (col < mx + 1)
		{
			c = arr[row][col] + '0';
			write (1, &c, 1);
			if (col != mx)
				write (1, " ", 1);
			col++;
		}
		write (1, "\n", 1);
		row++;
	}
}
