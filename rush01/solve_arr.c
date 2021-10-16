/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:32:45 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 02:45:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	first_step_col(int **arr, int max_num)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	while (i <= max_num)
	{
		j = 1;
		chk = arr[0][i] - arr[max_num + 1][i];
		if (col < 0)
			chk *= -1;
		if (col == max_num - 1)
		{
			while (j <= max_num)
			{
				arr[j][i] = j;
				j++;
			}
		}
	}
}
