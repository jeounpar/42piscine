/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:16:34 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/13 19:16:43 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pr_under_10(int tmp)
{
	char	c;

	c = tmp + '0';
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
			pr_under_10(tmp);
			break ;
		}
		cnt = 0;
		return_fr_num(&tmp, &cnt);
		pr_under_10(tmp);
		sum = 1;
		sum_10(&sum, cnt);
		num = num - tmp * sum;
		tmp = num;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, &"-", 1);
		write (1, &"2", 1);
		pr_int(147483648);
	}
	else if (nb < 0)
	{
		nb *= -1;
		write (1, &"-", 1);
		pr_int(nb);
	}
	else
		pr_int(nb);
}
