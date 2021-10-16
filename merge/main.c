/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:00:42 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 22:47:49 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char *argv[])
{
	int	max_num;
	int	*nums;
	int	**arr;

	max_num = get_maxnum(argv[1]);
	if (argc != 2 || check_input(argv[1], max_num) != 1)
		write (1, "Error\n", 6);
	else
	{
		nums = get_nums(argv[1]);
		arr = make_arr(max_num);
		wr_arr(arr, nums, max_num);
		ft_solve(arr, max_num, 0);
		free (nums);
		free (arr);
	}
	return (0);
}
