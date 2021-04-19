/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:56:16 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 17:07:03 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_len_int(uintmax_t n)
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

uintmax_t	ft_neg(uintmax_t nb, intmax_t	aux1)
{		
	if (aux1 < 0)
		nb = (uintmax_t) - aux1;
	else
		nb = aux1;
	return (nb);
}

int	ft_len(t_flags *flags, uintmax_t nb)
{	
	int len;

	len = print_len_int(nb);
	if (nb == 0 && flags->dot == 1)
		len = 0;
	else if (nb == 0)
		len = 1;
	return (len);
}

static intmax_t	parse_di(va_list *arg_ptr_, t_flags *flags)
{	
	if (flags->l == 1)
		return (va_arg(*arg_ptr_, long));
	if (flags->ll == 2)
		return (va_arg(*arg_ptr_, long long));
	if (flags->h == 1)
		return ((short)va_arg(*arg_ptr_, int));
	if (flags->hh == 2)
		return ((char)va_arg(*arg_ptr_, int));
	return (va_arg(*arg_ptr_, int));
}

int	ft_printdi(char c, va_list *arg_ptr_, t_flags *flags)
{
	intmax_t	aux1;
	uintmax_t	nb;
	int			len;
	int			len_spaces;
	int			count;

	count = 0;
	len_spaces = 0;
	nb = 0;
	aux1 = parse_di(arg_ptr_, flags);
	nb = ft_neg(nb, aux1);
	
	if (aux1 < 0)
		flags->neg = 1;
	len = ft_len(flags, nb);
	len_spaces = ft_flagsld(flags, len);
	count += ft_flagsd(c, flags, len, aux1);
	if (len)
		ft_putnbr(nb);
	if (flags->minus == 1)
		count += ft_putspaces(flags->spacesleft, c, len_spaces, flags->neg);
	count += len;
	return (count);
}
