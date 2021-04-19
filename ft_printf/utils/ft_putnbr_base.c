/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:21:41 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/14 16:30:15 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nbr, char *base, va_list nb)
{
	unsigned long	holder;
	unsigned long	base_length;

	base_length = ft_strlen(base);
	holder = nbr;
	if (holder >= base_length)
	{
		ft_putnbr_base(holder / base_length, base, nb);
		ft_putnbr_base(holder % base_length, base, nb);
	}
	else
		ft_putchar(base[holder]);
}
