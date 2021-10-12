/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:05:40 by junhyuki          #+#    #+#             */
/*   Updated: 2021/10/10 16:06:33 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int line, int row, int l_line, int l_row)
{
	if (line == 0)
	{
		if (row == 0)
			ft_putchar('o');
		else if (row == l_row - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else if (line == l_line - 1)
	{
		if (row == 0)
			ft_putchar('o');
		else if (row == l_row - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (row == 0 || row == l_row - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	line;
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	line = 0;
	while (line < y)
	{
		row = 0;
		while (row < x)
		{
			ft_print(line, row, y, x);
			row++;
		}
		ft_putchar('\n');
		line++;
	}
}
