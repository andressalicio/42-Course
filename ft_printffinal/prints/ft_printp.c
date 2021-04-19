/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:13:26 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 16:01:23 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_len_p(unsigned long int n)
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

static int	base_is_invalid(char *base)
{
	int	i;
	int	m;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		m = i + 1;
		while (base[m])
			if (base[m++] == base[i])
				return (1);
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

void	ft_putnbr_base_ul(unsigned long int nbr, char *base, va_list nb)
{
	unsigned long int	holder;
	unsigned long int	base_length;

	if (base_is_invalid(base))
		return ;
	base_length = ft_strlen(base);
	holder = nbr;
	if (holder >= base_length)
	{
		ft_putnbr_base_ul(holder / base_length, base, nb);
		ft_putnbr_base_ul(holder % base_length, base, nb);
	}
	else
		ft_putchar(base[holder]);
}

int	ft_printp(char c, va_list *arg_ptr, t_flags *flags)
{
	unsigned long int	aux2;
	int					len;
	int					len_spaces;
	int					count;

	count = 0;
	aux2 = va_arg(*arg_ptr, unsigned long int);
	len = print_len_p(aux2);
	if (aux2 == 0)
		len += 3;
	else
		len += 2;
	len_spaces = len;
	if (flags->spacesright > 0)
		count += ft_putspaces(flags->spacesright, c, len_spaces, flags->neg);
	ft_putstr("0x");
	ft_putnbr_base_ul(aux2, "0123456789abcdef", *arg_ptr);
	if (flags->minus == 1)
		count += ft_putspaces(flags->spacesleft, c, len_spaces, flags->neg);
	count += len;
	return (count);
}
