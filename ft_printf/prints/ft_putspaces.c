/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:33:56 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 17:06:54 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_space_sc(int spaces, int len)
{
	if (len > spaces)
		return (0);
	else
		return (spaces - len);
}

static int	print_space_num(int spaces, int len, int neg)
{
	int	spaces_num;

	spaces_num = 0;
	if (len > spaces)
		spaces_num = 0;
	else
		spaces_num = spaces - len;
	if (neg == 1)
		spaces_num--;
	return (spaces_num);
}

int	ft_putspaces(int spaces, char c, int len, int neg)
{
	int	temp;
	int	ret;

	temp = spaces;
	if (c == 's' || c == 'c')
		temp = print_space_sc(temp, len);
	else
		temp = print_space_num(temp, len, neg);
	ret = temp;
	while (temp-- > 0)
		ft_putchar(' ');
	return (ret);
}
