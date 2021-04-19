/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:48:32 by ande-sou          #+#    #+#             */
/*   Updated: 2021/03/12 13:48:32 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.zero = 0;
	flags.spacesleft = 0;
	flags.spacesright = 0;
	flags.size_of_dot = 0;
	flags.size_of_zero = 0;
	flags.l = 0;
	flags.h = 0;
	flags.ll = 0;
	flags.hh = 0;
	flags.wprint = 4;
	flags.hash = 0;
	flags.neg = 0;
	return (flags);
}

int ft_print(char c, t_flags *flags,  va_list *arg_ptr, int count)
{
	if (c == 's' && !flags->l)
		count += ft_prints(c, arg_ptr, flags);
	else if (c == 'c')
		count += ft_printc(c, arg_ptr, flags);
	else if (c == 'd' || c == 'i')
		count += ft_printdi(c, arg_ptr, flags);
	else if (c == 'p')
		count += ft_printp(c, arg_ptr, flags);
	else if (c == 'u')
		count += ft_printu(c, arg_ptr, flags);
	else if (c == 'x' || c == 'X')
		count += ft_printx(c, arg_ptr, flags);
	else if (c == 'n')
		ft_printn(arg_ptr, flags, count);
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_put_args(const char *save, va_list *arg_ptr)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;	
	while (1)
	{
		flags = ft_init_flags();
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i = ft_flags(save, ++i, &flags, arg_ptr);
			count = ft_print(save[i], &flags, arg_ptr, count);			
			if (save[i] == 's' && flags.l > 0)
				count += ft_print_ls(save, arg_ptr, &flags);			
		}
		else
			count += ft_putchar(save[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list		arg_ptr;
	char		*save;
	int			count;	

	count = 0;
	save = ft_strdup(input);
	va_start(arg_ptr, input);
	count += ft_put_args(save, &arg_ptr);
	va_end(arg_ptr);
	free((char *)save);
	return (count);
}
