/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:04:25 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 16:02:42 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_len(uintmax_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_flagsl(t_flags *flags, int len)
{
	int len_spaces;
	
	len_spaces = len;
	if (flags->zero == 1 && flags->size_of_zero > len)
		len_spaces = flags->size_of_zero;
	else if (flags->dot == 1 && flags->size_of_dot > len)
		len_spaces = flags->size_of_dot;
	return (len_spaces);
}

int	ft_flagsu(char c, t_flags *flags, int len)
{
	int	count;
	int	len_spaces;

	count = 0;
	len_spaces = ft_flagsl(flags, len);
	if (flags->spacesright > 0)
		count += ft_putspaces(flags->spacesright, c, len_spaces, flags->neg);
	if (flags->dot == 1)
		count += ft_putzero(flags->size_of_dot, c, len);
	if (flags->zero == 1)
		count += ft_putzero(flags->size_of_zero, c, len);
	return (count);
}

static uintmax_t	parse_u(va_list *arg_ptr_, t_flags *flags)
{
	if (flags->l == 1)
		return (va_arg(*arg_ptr_, unsigned long));
	if (flags->ll == 2)
		return (va_arg(*arg_ptr_, unsigned long long));
	if (flags->h == 1)
		return ((unsigned short)va_arg(*arg_ptr_, unsigned int));
	if (flags->hh == 2)
		return ((unsigned char)va_arg(*arg_ptr_, unsigned int));
	return (va_arg(*arg_ptr_, unsigned int));
}

int	ft_printu(char c, va_list *arg_ptr_, t_flags *flags)
{
	uintmax_t	aux3;
	int			len;
	int			len_spaces;
	int			count;

	count = 0;
	len_spaces = 0;
	aux3 = parse_u(arg_ptr_, flags);
	len = print_len(aux3);
	if (aux3 == 0 && flags->dot == 1)
		len = 0;
	else if (aux3 == 0)
		len = 1;
	len_spaces = ft_flagsl(flags, len);
	count += ft_flagsu(c, flags, len);
	if (len)
		ft_putnbr(aux3);
	if (flags->minus > 0)
		count += ft_putspaces(flags->spacesleft, c, len_spaces, flags->neg);
	count += len;
	return (count);
}
