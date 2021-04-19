/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:09:16 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 17:18:16 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_len_x(uintmax_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	print_len_x2(uintmax_t n, t_flags *flags, int len, char c)
{	
	if (n == 0 && flags->dot == 1 && !flags->size_of_dot)
		len = 0;
	else if (n == 0)
		len = 1;
	// printf("\n %ju \n ", n);
	if (flags->hash == 1 && len > 0 && n != 0)
		len += 2;
	if (flags->hash == 1 && len > 0 && n != 0)
	{
		if (c == 'x')
			ft_putstr("0x");
		if (c == 'X')
			ft_putstr("0X");
	}

	return (len);
}

void	ft_putbase(uintmax_t n, char c, va_list nb)
{
	if (c == 'x')
		ft_putnbr_base(n, "0123456789abcdef", nb);
	if (c == 'X')
		ft_putnbr_base(n, "0123456789ABCDEF", nb);
}

static uintmax_t	parse_x(va_list *arg_ptr_, t_flags *flags)
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

int	ft_printx(char c, va_list *arg_ptr_, t_flags *flags)
{
	uintmax_t	aux3;
	int			len;
	int			len_spaces;
	int			count;

	count = 0;
	len_spaces = 0;
	aux3 = parse_x(arg_ptr_, flags);
	len = print_len_x(aux3);
	len = print_len_x2(aux3, flags, len, c);
	len_spaces = len;	
	len_spaces = ft_flagslx(flags, len);
	if (flags->hash == 1 && len > 0 && aux3 != 0 && flags->dot == 1)
        len -= 2;
	count += ft_flagsx(c, flags, len);
	if (len)
		ft_putbase(aux3, c, *arg_ptr_);
	if (flags->hash == 1 && len > 0 && aux3 != 0 && flags->dot == 1)
		len += 2;
	// printf("\n %d \n ", len_spaces);
	if (flags->minus > 0)
		count += ft_putspaces(flags->spacesleft, c, len_spaces, flags->neg);
	count += len;
	return (count);
}
