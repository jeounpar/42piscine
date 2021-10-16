/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:00:42 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 02:07:17 by marvin           ###   ########.fr       */
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
		free (nums);
		free (arr);
	}
	return (0);
}
