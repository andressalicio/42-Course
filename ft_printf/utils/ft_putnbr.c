/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:21:41 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/21 11:56:37 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(intmax_t nb)
{
	uintmax_t	holder;

	holder = nb;
	if (nb < 0)
	{
		holder = -nb;
	}
	if (holder >= 10)
	{
		ft_putnbr(holder / 10);
		ft_putnbr(holder % 10);
	}
	else
		ft_putchar(holder + '0');
}

void	ft_putnbrui(uintmax_t nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
