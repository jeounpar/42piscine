/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:56:27 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/11 19:31:34 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aa;
	int	bb;

	if (*b != 0)
	{
		aa = *a / *b;
		bb = *a % *b;
		*a = aa;
		*b = bb;
	}
}
