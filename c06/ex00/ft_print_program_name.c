/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:47:50 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/20 11:47:58 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*str;

	i = 0;
	if (argc > 0)
	{
		str = argv[0];
		while (str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
		}
		write (1, "\n", 1);
	}
	return (0);
}
