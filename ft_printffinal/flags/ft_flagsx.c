/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:17:49 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/15 17:17:49 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagslx(t_flags *flags, int len)
{
	int len_spaces;
	len_spaces = len;
	if (flags->zero == 1 && flags->size_of_zero > len_spaces)
		len_spaces = flags->size_of_zero;
	else if (flags->dot == 1 && flags->size_of_dot > len_spaces)
		len_spaces = flags->size_of_dot;
	return (len_spaces);
}

int	ft_flagsx(char c, t_flags *flags, int len)
{
	int	count;
	int	len_spaces;

	count = 0;
	len_spaces = ft_flagslx(flags, len);
	if (flags->spacesright > 0)
	{
		count += ft_putspaces(flags->spacesright, c, len_spaces, flags->neg);
		if (flags->neg > 0)
			count += 1;
		else
			count += 0;
	}
	if (flags->dot == 1)
		count += ft_putzero(flags->size_of_dot, c, len);
	if (flags->zero == 1)
		count += ft_putzero(flags->size_of_zero, c, len);
	return (count);
}
