/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/10/12 00:02:45 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	vo_st;

	i = 0;
	vo_st = 1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A') || 
				(str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			vo_st = 1;
		else if (vo_st == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - ('a' - 'A');
			vo_st = 0;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + ('a' - 'A');
		}
		i++;
	}
	return (str);
}

int main(void)
{
	char str[] = "saLUt, CoMMent TU VAS ? 42mOTs quaRANte-dEUX; cinqUANte+eT+UN";
	char src[] = "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un";
	printf("%s\n", ft_strcapitalize(str));
	printf("%s\n", src);

	return 0;
}
