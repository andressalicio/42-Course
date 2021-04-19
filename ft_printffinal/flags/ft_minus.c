/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:49:48 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/12 18:49:48 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == 'n') || (c == '%'));
}

t_flags	ft_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	flags.spacesleft = 0;
	flags.spacesright = 0;
	return (flags);
}

t_flags	ft_dot(t_flags flags)
{
	flags.dot = 1;
	return (flags);
}

t_flags	ft_length_modifiers(const char *save, int i, t_flags flags)
{
	if (save[i] == 'l')
		flags.l += 1;
	if (save[i] == 'l' && save[i + 1] == 'l')
		flags.ll += 2;
	if (save[i] == 'h')
		flags.h += 1;
	if (save[i] == 'h' && save[i + 1] == 'h')
		flags.hh += 2;
	flags.zero = 0;
	flags.spacesleft = 0;
	flags.spacesright = 0;
	return (flags);
}
