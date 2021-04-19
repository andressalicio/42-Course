/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:00:41 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 17:15:37 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrl(char *str, int len)
{
	write(1, str, len);
}

int	ft_flagsstr(t_flags *flags, int len_spaces, int len)
{
	if (flags->dot == 1 && flags->size_of_dot < len_spaces)
		len_spaces = flags->size_of_dot;
	if (flags->zero == 1 && flags->size_of_zero > len)
		len_spaces = flags->size_of_zero;
	return (len_spaces);
}

int	ft_prints(char c, va_list *arg_ptr, t_flags *flags)
{
	char		*aux;
	int			len;
	int			len_spaces;
	int			count;
	int 		len_print_override;

	count = 0;
	len_print_override = 0;
	aux = va_arg(*arg_ptr, char *);
	if (aux == NULL)
	{
		aux = "(null)";
		if (flags->dot > 0 && flags->size_of_dot < 0) {
			flags->minus = 0;
			flags->dot = flags->dot * -1;
			len_print_override = 6;
		}
	}

	// printf("\n%d\n", !aux);
	len = ft_strlen(aux);
	len_spaces = len;
	len_spaces = ft_flagsstr(flags, len_spaces, len);
	if (flags->spacesright > 0)
		count += ft_putspaces(flags->spacesright, c, len_spaces, flags->neg);
	ft_putstrl(aux, len_print_override > 0 ? len_print_override : len_spaces);
	if (flags->minus > 0)
		count += ft_putspaces(flags->spacesleft, c, len_spaces, flags->neg);
	count += len_spaces;
	return (count);
}
