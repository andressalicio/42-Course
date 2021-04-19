/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:45:24 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/14 11:43:32 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printn(va_list *arg_ptr_, t_flags *flags, intmax_t count)
{
	void	*n;

	n = va_arg(*arg_ptr_, long long int *);
	if (flags->l == 1)
		*(long *)n += count + 1;
	else if (flags->ll == 2)
		*(long long *)n += count + 1;
	else if (flags->h == 1)
		*(short *)n += count + 1;
	else if (flags->hh == 2)
		*(char *)n += count + 1;
	else
		*(int *)n += count + 1;
	return (count);
}
