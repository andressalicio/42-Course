/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:30:17 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/14 14:31:13 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wcharlen(wchar_t c)
{
	if (c < 0x80)
		return (1);
	if (c < 0x0800)
		return (2);
	if (c < 0x010000)
		return (3);
	if (c < 0x110000)
		return (4);
	return (0);
}

int	ft_print_wchars( t_flags *flags, size_t size, unsigned char str[4])
{
	int	count;

	count = 0;
	flags->wprint -= size;
	if (flags->wprint < 0)
		size = flags->wprint + 4;
	write(1, str, size);
	count += size;
	return (count);
}

int	ft_putwchar(wchar_t c, t_flags *flags)
{
	unsigned char	str[4];
	size_t			size;

	size = ft_wcharlen(c);
	if (size == 1)
		str[0] = ((c >> 0) & 0x7F) | 0x00;
	else if (size == 2)
	{
		str[0] = ((c >> 6) & 0x1F) | 0xC0;
		str[1] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (size == 3)
	{
		str[0] = ((c >> 12) & 0x0F) | 0xE0;
		str[1] = ((c >> 6) & 0x3F) | 0x80;
		str[2] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (size == 4)
	{
		str[0] = ((c >> 18) & 0x07) | 0xF0;
		str[1] = ((c >> 12) & 0x3F) | 0x80;
		str[2] = ((c >> 6) & 0x3F) | 0x80;
		str[3] = ((c >> 0) & 0x3F) | 0x80;
	}
	return (ft_print_wchars(flags, size, str));
}
