/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:18:18 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/11 21:18:22 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putc(char c)
{
	write (1, &c, 1);
}

void	ft_print_arr(int n, int arr[])
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		ft_putc(arr[idx] + '0');
		idx++;
	}
	if (arr[0] == 10 - n)
	{
	}
	else
	{
		ft_putc(',');
		ft_putc(' ');
	}
}

void	ft_combn_recur(int n, int cur_idx, int arr[], int to_print)
{
	int	max_num;

	if (cur_idx == n)
		ft_print_arr(n, arr);
	else
	{
		to_print++;
		max_num = 10 - n + cur_idx;
		while (to_print <= max_num)
		{
			arr[cur_idx] = to_print;
			ft_combn_recur(n, cur_idx + 1, arr, to_print);
			to_print++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	ft_combn_recur(n, 0, arr, -1);
}
