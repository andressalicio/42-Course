/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextparam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:51:26 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/12 18:51:26 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	from_str_to_num(char str, int current_num)
{
	if (current_num == 0)
		current_num = str - '0';
	else
		current_num = str + current_num * 10 - '0';
	return (current_num);
}

int	getNextParam(va_list *arg_ptr_, int current_num)
{
	if (current_num == 0)
		current_num = va_arg(*arg_ptr_, int);
	else
		current_num = va_arg(*arg_ptr_, int) + current_num * 10;
	return (current_num);
}

int	apply2Nums(int num1, int num2)
{
	if (num1 == 0)
		num1 = num2;
	else
		num1 = num2 * 10;
	return (num1);
}
