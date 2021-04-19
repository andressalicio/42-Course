/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:42:12 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 14:10:22 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isnumber(const char *save, int i, t_flags *flags)
{
	if (flags->zero != 1 && flags->dot != 1 && flags->minus != 1)
		flags->spacesright = from_str_to_num(save[i], flags->spacesright);
	else if (flags->minus == 1 && flags->dot != 1)
		flags->spacesleft = from_str_to_num(save[i], flags->spacesleft);
	else if (flags->dot == 1)
	{
		if (flags->zero == 1)
		{
			flags->spacesright = flags->size_of_zero;
			flags->size_of_zero = 0;
			flags->zero = 0;
		}
		flags->size_of_dot = from_str_to_num(save[i], flags->size_of_dot);
	}
	else if (flags->zero == 1)
		flags->size_of_zero = from_str_to_num(save[i], flags->size_of_zero);
}

void	ft_isstar(t_flags *flags, va_list *arg_ptr_)
{
	int	nextParam;

	nextParam = 0;
	nextParam = getNextParam(arg_ptr_, nextParam);
	// printf("\n nextparam %d \n", nextParam);
	if (nextParam < 0 && flags->dot != 1)
	{
			nextParam = nextParam * -1;
			flags->minus = 1;
	}
	if (flags->zero != 1 && flags->dot != 1 && flags->minus != 1)
		flags->spacesright = apply2Nums(flags->spacesright, nextParam);
	else if (flags->minus == 1 && flags->dot != 1)
		flags->spacesleft = apply2Nums(flags->spacesleft, nextParam);
	else if (flags->dot == 1)
	{
		flags->size_of_dot = apply2Nums(flags->size_of_dot, nextParam);
		if (flags->zero == 1)
		{
			flags->spacesright = flags->size_of_zero;
			flags->size_of_zero = 0;
			flags->zero = 0;
		}
	}
	else if (flags->zero == 1)
		flags->size_of_zero = apply2Nums(flags->size_of_zero, nextParam);
}

int	ft_flags(const char *save, int i, t_flags *flags, va_list *arg_ptr_)
{
	while (save[i])
	{
		if (save[i] == '#')
			flags->hash = 1;
		if (save[i] == '0' && flags->spacesright == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '-')
			*flags = ft_minus(*flags);
		if (save[i] == '.')
			*flags = ft_dot(*flags);
		if (ft_is_in_type_list(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		if (save[i] >= '0' && save[i] <= '9')
			ft_isnumber(save, i, flags);
		else if (save[i] == '*')
			ft_isstar(flags, arg_ptr_);
		if (save[i] == 'l' || save[i] == 'h')
			*flags = ft_length_modifiers(save, i, *flags);
		i++;
	}
	return (i);
}
