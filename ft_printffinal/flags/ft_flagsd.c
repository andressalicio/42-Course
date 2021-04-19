/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:51:49 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 16:51:49 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagsneg(intmax_t aux1, t_flags *flags)
{
	if (aux1)
		ft_putchar('-');
	if (flags->zero == 1)
		flags->size_of_zero--;
}

int ft_flagsspaces(t_flags *flags, char c, int len_spaces, int count)
{
	if (flags->spacesright > 0)
	{
	count += ft_putspaces(flags->spacesright, c, len_spaces, flags->neg);
	if (flags->spacesright <= flags->size_of_dot && flags->neg == 1)
		count++;
	}
	if ((flags->spacesleft <= flags->size_of_dot) 
	&& flags->dot == 1 && flags->minus == 1 && flags->neg == 1)
		count++;
	return (count);
}

int	ft_flagsld(t_flags *flags, int len)
{
	int len_spaces;
	
	len_spaces = len;
	if (flags->zero == 1 && flags->size_of_zero > len)
		len_spaces = flags->size_of_zero;
	else if (flags->dot == 1 && flags->size_of_dot > len)
		len_spaces = flags->size_of_dot;
	return (len_spaces);
}

int	ft_flagsd(char c, t_flags *flags, int len, intmax_t aux1)
{
	int	count;
	int	len_spaces;

	count = 0;
	len_spaces = ft_flagsld(flags, len);
	count += ft_flagsspaces(flags, c, len_spaces, count);	
	if (flags->neg == 1)
	{
		ft_flagsneg(aux1, flags);
		count++;
	}
	if (flags->dot == 1)
		count += ft_putzero(flags->size_of_dot, c, len);
	if (flags->zero == 1)
		count += ft_putzero(flags->size_of_zero, c, len);
	return (count);
}