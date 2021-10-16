/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:37:43 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 01:59:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	wr_arr(int **arr, int *nums, int max_num)
{
	int	i;
	int	idx;

	i = 1;
	idx = 0;
	while (i <= max_num)
	{
		arr[0][i] = nums[idx];
		arr[max_num + 1][i] = nums[idx + max_num];
		i++;
		idx++;
	}
	i = 1;
	idx = max_num * 2;
	while (i <= max_num)
	{
		arr[i][0] = nums[idx];
		arr[i][5] = nums[idx + max_num];
		i++;
		idx++;
	}
}
