/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:27:22 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/17 22:27:30 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
int	is_wspc(char c) 공백문자 검사해주는 함수
공백문자가 있으면 참
없으면 거짓
*/
int	is_wspc(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

/*
입력받은 문자열에 숫자 외에 다른 문자가 있는지 검사해주는 함수

cnt는 공백을 기준으로 숫자의 개수를 저장
ex) "1 2 3 4 1 2 3 4" 이 때 cnt == 8
ex) "1 2 3 4 1 2 34" 이 때는 cnt == 7
*/
int	chk_other(char *str, int cnt)
{
	int	i;
	int	mx;

	mx = cnt / 4; // 최대 숫자는 숫자의 개수 / 4
	i = 0;
	if (mx * 4 != cnt) //지도에 들어가는 각 방향에서 바라봤을 때 숫자의 개수는 최대 숫자 * 4
		return (1);
	while (str[i] != '\0')
	{
		if (is_wspc(str[i])) //공백은 건너뛰고
			;
		else if (str[i] < '1' || str[i] > '9') //1 ~ 9가 아닌 숫자가 있다면 리턴 1
			return (1);
		i++;
	}
	return (0); // 다른 문자가 없다면 리턴 0
}

int	check_input(char *str, int *mx)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = 1; //flag는 공백을 기준으로 공백 바로 다음의 숫자의 개수를 세주기위해 선언
	while (str[i] != '\0')
	{
		if (is_wspc(str[i])) //str[i]가 공백이면 flag = 1
			flag = 1;
		if ((flag > 0) && (str[i] >= '1' && str[i] <= '9'))
		{ // 공백 다음의 숫자의 개수를 세줌
			cnt++;
			flag = 0;
		}
		i++;
	}
	if (cnt == 0 || cnt % 4 != 0) //공백 다음의 숫자가 없거나 
	// 각 방향에서 바라봤을때의 숫자의 개수는 항상 4의 배수이므로 cnt가 4의 배수가 아니라면
	// 리턴 0
		return (0);
	if (chk_other(str, cnt))
		return (0);
	//문자열 검사가 끝났으면 mx에 최대 값인 cnt / 4를 넣어줌
	*mx = cnt / 4;
	return (1);
}
