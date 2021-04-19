/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:36:11 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/14 12:18:18 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_zero_sc(int spaces, int len)
{
	if (len > spaces)
		return (0);
	else
		return (spaces - len);
}

static int	print_zero_num(int spaces, int len)
{
	if (len > spaces)
		return (0);
	else
		return (spaces - len);
}

int	ft_putzero(int zero, char c, int len)
{
	int	temp;
	int	ret;

	temp = zero;
	if (c == 's' || c == 'c')
		temp = print_zero_sc(temp, len);
	else
		temp = print_zero_num(temp, len);
	ret = temp;
	while (temp-- > 0)
		ft_putchar('0');
	return (ret);
}
