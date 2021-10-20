/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:36:24 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:25 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int	ft_strlen(char *str);
int	valid_base(char *str, int len);

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_len(unsigned int n, char *base, int neg)
{
	int	cnt;
	int				len;

	cnt = 0;
	len = ft_strlen(base);
	if (neg)
		cnt++;
	while (true)
	{
		cnt++;
		if (n / len == 0)
			break ;
		n /= len;
	}
	return (cnt);
}

char	*ft_inchar(unsigned	int num, char *base_to, int neg)
{
	int		len;
	int		i;
	char	*str;
	int		size;

	size = get_len(num, base_to, neg);
	len = ft_strlen(base_to);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	if (neg)
	{
		i = 1;
		str[0] = '-';
	}
	while (i < size)
	{
		printf("number : %d\n", num);
		str[size - i - (!neg)] = base_to[num % len];
		num /= len;
		i++;
	}
	str[i] = '\0';
	return (str);
}