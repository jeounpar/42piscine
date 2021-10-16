/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:00:42 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 20:29:07 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

int	ft_is_true(int arr[6][6], int pos)
{
	if (!ft_row_diff_check(arr) || ft_col_diff_check(arr)
			|| !ft_view_up_check(arr, pos)
			|| !ft_view_down_check(arr, pos)
			|| !ft_view_left_check(arr, pos)
			|| !ft_view_right_check(arr, pos))
		return (0);
	return (1);
}

int	ft_solve(int arr[6][6], int pos)
{
	int	i;
	int	x;
	int	y;

	if (pos == 16)
	{
		ft_print_solution(arr);
		return (1);
	}
	i = 1;
	x = (pos / 4) + 1;
	y = (pos % 4) + 1;
	while (i <= 4)
	{
		arr[x][y] = i;
		if (ft_is_true(arr, pos))
		{
			if (ft_solve(arr, pos + 1))
				return (1);
		}
		i++;
	}
	arr[x][y] = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	int	max_num;
	int	*nums;
	int	**arr;

	int	test[6][6] = {
		{0, 4, 3, 2, 1, 0},
		{4, 0, 0, 0, 0, 1},
		{3, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 2},
		{1, 0, 0, 0, 0, 2},
		{0, 1, 2, 2, 2, 0}
	};

	max_num = get_maxnum(argv[1]);
	if (argc != 2 || check_input(argv[1], max_num) != true)
		write (1, "Error\n", 6);
	else
	{
		nums = get_nums(argv[1]);
		arr = make_arr(max_num);
		wr_arr(arr, nums, max_num);
		for (int i = 0; i < max_num + 2; i++){
			for (int j = 0; j < max_num + 2; j++){
				printf ("%d ", arr[i][j]);
			}
			printf("\n");
		}

		if (!ft_solve(test, 0))
			write (1, "EError\n", 7);

		free (nums);
		free (arr);
	}
	return (0);
}
