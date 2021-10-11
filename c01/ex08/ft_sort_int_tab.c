/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:19:45 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/10 19:27:45 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	a;
	int	b;

	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size - 1)
		{
			if (tab[b] > tab[b + 1])
			{
				tmp = tab[b];
				tab[b] = tab[b + 1];
				tab[b + 1] = tmp;
			}
			b++;
		}
		a++;
	}
}
