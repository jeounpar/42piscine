/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_non_printable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:48:16 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/12 15:34:52 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_16base(int mod)
{
	char	c;

	if (mod < 10)
		c = mod + '0';
	else
		c = 'a' + mod - 10;
	write (1, &"0", 1 );
	write (1, &c, 1 );
}

void	ft_print_non_printable(char *str)
{
	int	i;
	int	a;
	int	mod;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			write (1, &"\\", 1);
			a = str[i] - 0;
			while (1)
			{
				mod = a % 16;
				print_16base(mod);
				a = a / 16;
				if (a == 0)
					break ;
			}
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}

int main(void)
{
	char str[]="Coucou\ntu vas bien ? _\a\b\f\n\r\t\v";
	ft_print_non_printable(str);
	return 0;
}
