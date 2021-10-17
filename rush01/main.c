/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:00:42 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 16:25:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

bool	check_input(char *str, int max_num);

int	main(int argc, char *argv[])
{
	int	max_num;
	int	*nums;
	int	**arr;

	max_num = get_maxnum(argv[1]);
	if (argc != 2 || check_input(argv[1], max_num) != true)
		write (1, "Error\n", 6);
	else
	{
		nums = get_nums(argv[1]);
		arr = make_arr(max_num);
		wr_arr(arr, nums, max_num);
		ft_solve(arr, max_num, 0);
		// for (int i = 0; i < max_num + 2; i++){
		// 	for (int j = 0; j < max_num + 2; j++){
		// 		printf("%d ", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }
		free (nums);
		free (arr);
	}
	return (0);
}
