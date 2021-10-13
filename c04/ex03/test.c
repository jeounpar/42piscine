/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:30:33 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/13 20:16:11 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	negative_cnt;
	int	result;

	i = 0;
	result = 0;
	negative_cnt = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			negative_cnt++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = str[i] - '0' + result * 10;
		i++;
	}
	if (negative_cnt % 2 != 0)
		result *= -1;
	return (result);
}

int main(void)
{
	char str[] = "   ---+--+1234ab567";
	printf("%d\n", ft_atoi(str));
	return 0;
}
