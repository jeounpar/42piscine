/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:09:25 by ibae              #+#    #+#             */
/*   Updated: 2021/10/17 22:33:10 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

# include <stdlib.h>

int		check_input(char *str, int *mx);
int		*get_nums(char *str);
int		**make_arr(int num);

void	wr_arr(int **arr, int *nums, int max_num);
void	ft_print_solution(int **arr, int mx);

int		val_row(int **arr, int mx);
int		val_col(int **arr, int mx);

int		val_colup(int **arr, int mx, int pos);
int		val_coldown(int **arr, int mx, int pos);
int		val_rowleft(int **arr, int mx, int pos);
int		val_rowright(int **arr, int mx, int pos);
int		ft_solve(int **arr, int mx, int pos);

#endif
