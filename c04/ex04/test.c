/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:18:34 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/19 22:46:39 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int main(void)
{
	char base[] = "point.";
	unsigned long c;

	c = 0;
	while (c < (sizeof(base) - 1))
	{
		ft_putnbr_base(c, base);
		c++;
	}
	c = 0;
	while (c < (sizeof(base) - 1))
	{
		ft_putnbr_base(c, base);
		c++;
	}
	printf("\n");
	ft_putnbr_base(-1, base);
	printf("\n");
}
