/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:09:25 by ibae              #+#    #+#             */
/*   Updated: 2021/10/16 14:31:19 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

# include <stdlib.h>

# include <stdbool.h>

bool	check_input(char *str, int max_num);

int		get_maxnum(char *str);
int		*get_nums(char *str);
int		**make_arr(int num);

void	wr_arr(int **arr, int *nums, int max_num);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_solution(int arr[6][6]);

int		ft_row_diff_check(int arr[6][6]);
int		ft_col_diff_check(int arr[6][6]);

int		ft_view_up_check(int arr[6][6], int pos);
int		ft_view_down_check(int arr[6][6], int pos);
int		ft_view_left_check(int arr[6][6], int pos);
int		ft_view_right_check(int arr[6][6], int pos);

#endif
