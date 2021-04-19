/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:47:38 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 16:04:43 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagslc(t_flags *flags, int len_spaces, int len)
{
	if (flags->zero == 1 && flags->size_of_zero > len)
		len_spaces = flags->size_of_zero;
	return (len_spaces);
}

int	ft_flagsc(char c, t_flags *flags, int len)
{
	int	count;
	int	len_spaces;

	count = 0;
	len_spaces = len;
	len_spaces = ft_flagslc(flags, len_spaces, len);
	if (flags->spacesright > 0)
		count += ft_putspaces(flags->spacesright, c, len_spaces, flags->neg);
	if (flags->zero == 1)
		count += ft_putzero(flags->size_of_zero, c, len);
	return (count);
}

int	ft_printc(char c, va_list *arg_ptr, t_flags *flags)
{
	intmax_t	aux1;
	int			len;
	//int			len_spaces;
	int			count;	

	count = 0;
	//len_spaces = 0;
	aux1 = va_arg(*arg_ptr, int);
	if (flags->l || flags->ll)
		len = ft_wcharlen(aux1);
	else
		len = 1;
	count += ft_flagsc(c, flags, len);
	if (flags->l > 0 || flags->ll > 0)
		ft_putwchar(aux1, flags);
	else
		ft_putchar(aux1);
	if (flags->minus > 0)
		count += ft_putspaces(flags->spacesleft, c, len, flags->neg);
	count += len;
	return (count);
}
