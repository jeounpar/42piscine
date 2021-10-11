/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:56:27 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/10 17:59:21 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aa;
	int	bb;

	aa = *a / *b;
	bb = *a % *b;
	*a = aa;
	*b = bb;
}

int main(void)
{
	int a = 12;
	int b = 5;

	ft_ultimate_div_mod(&a, &b);
	printf("%d %d\n", a ,b);
}
