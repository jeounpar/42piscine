/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/10/11 17:39:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	use_upper;

	i = 0;
	use_upper = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			use_upper = 1;
		if (use_upper > 0 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			use_upper = -1;
			str[i] = str[i] - ('a' - 'A');
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (str);
}

int main(void)
{
	char str[] = "salut, Comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s@@\n", str);
	printf("%s@@\n", ft_strcapitalize(str));

	return 0;
}
