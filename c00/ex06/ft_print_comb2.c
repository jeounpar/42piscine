/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:11:55 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/09 15:20:34 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pr_under_10(int tmp, int chk)
{
	char	c;

	c = tmp + '0';
	if (chk < 10)
	{
		write (1, &"0", 1);
	}
	write (1, &c, 1);
}

void	return_fr_num(int *tmp, int *cnt)
{
	int	cnts;
	int	num;

	cnts = *cnt;
	num = *tmp;
	while (num > 9)
	{
		num = num / 10;
		cnts++;
	}
	*tmp = num;
	*cnt = cnts;
}

void	sum_10(int *sum, int cnt)
{
	int	tmp;

	tmp = 1;
	while (cnt > 0)
	{
		cnt--;
		tmp *= 10;
	}
	*sum = tmp;
}

void	pr_int(int num)
{
	int	tmp;
	int	cnt;
	int	sum;
	int	chk;

	chk = num;
	tmp = num;
	while (num >= 0)
	{
		if (num < 10)
		{
			pr_under_10(tmp, chk);
			break ;
		}
		cnt = 0;
		return_fr_num(&tmp, &cnt);
		pr_under_10(tmp, chk);
		sum = 1;
		sum_10(&sum, cnt);
		num = num - tmp * sum;
		tmp = num;
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			pr_int(a);
			write (1, &" ", 1);
			pr_int(b);
			if (a != 98 || b != 99)
			{
				write (1, &",", 1);
				write (1, &" ", 1);
			}
			b++;
		}
		a++;
	}
}
