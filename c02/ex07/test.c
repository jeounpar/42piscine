/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:59:43 by marvin            #+#    #+#             */
/*   Updated: 2021/10/11 16:07:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
			str[idx] = str[idx] - ('a' - 'A');
		idx++;
	}
	return (str);
}

int main(void)
{
	char str[]="abCdeFghIKlMnop";
	printf("%s\n", str);
	printf("%s\n", ft_strupcase(str));

	return 0;
}
