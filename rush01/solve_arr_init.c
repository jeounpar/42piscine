/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_arr_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:32:45 by marvin            #+#    #+#             */
/*   Updated: 2021/10/16 13:11:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	first_step_colup(int **arr, int max_num);
void	first_step_coldown(int **arr, int max_num);
void	first_step_rowleft(int **arr, int max_num);
void	first_step_rowright(int **arr, int max_num);

void	solve_arr_init(int **arr, int max_num)
{
	first_step_colup(arr, max_num);
	first_step_coldown(arr, max_num);
	first_step_rowleft(arr, max_num);
	first_step_rowright(arr, max_num);
}

void	first_step_colup(int **arr, int max_num)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i <= max_num)
	{
		if (arr[0][i] == 1 && arr[max_num + 1][i] == max_num)
		{
			k = 1;
			j = max_num;
			while (j >= 1)
			{
				arr[k][i] = j;
				j--;
				k++;
			}
		}
		i++;
	}
}

void	first_step_coldown(int **arr, int max_num)
{
	int	i;
	int	j;

	i = 1;
	while (i <= max_num)
	{
		if (arr[0][i] == max_num && arr[max_num + 1][i] == 1)
		{
			j = 1;
			while (j <= max_num)
			{
				arr[j][i] = j;
				j++;
			}
		}
		i++;
	}
}

void	first_step_rowleft(int **arr, int max_num)
{
	int	i;
	int	j;

	i = 1;
	while (i <= max_num)
	{
		if (arr[i][0] == max_num && arr[i][max_num + 1] == 1)
		{
			j = 1;
			while (j <= max_num)
			{
				arr[i][j] = j;
				j++;
			}
		}
		i++;
	}
}

void	first_step_rowright(int **arr, int max_num)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i <= max_num)
	{
		if (arr[i][0] == 1 && arr[i][max_num + 1] == max_num)
		{
			k = 1;
			j = max_num;
			while (j >= 1)
			{
				arr[i][k] = j;
				k++;
				j--;
			}
		}
		i++;
	}
}
