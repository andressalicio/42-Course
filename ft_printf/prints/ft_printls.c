/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:17:32 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/21 10:17:32 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(wchar_t *str, t_flags *flags, int len_spaces)
{
	int		i;

	if (flags->dot == 1 && flags->size_of_dot < len_spaces)
		len_spaces = flags->size_of_dot;
	i = 0;
	flags->wprint = len_spaces;
	while (str[i] && flags->wprint > 0)
		ft_putwchar(str[i++], flags);
}

int	ft_print_ls(const char *save, va_list *arg_ptr, t_flags *flags)
{
	int		i;
	wchar_t	*s;
	int		len;
	int		len_spaces;
	int		count;

	i = 0;
	count = 0;
	s = va_arg(*arg_ptr, wchar_t *);
	len = 0;
	while (s[i])
		len += ft_wcharlen(s[i++]);
	len_spaces = len;
	if (flags->dot == 1 && flags->size_of_dot < len_spaces)
		len_spaces = flags->size_of_dot;
	if (flags->spacesright > 0)
		count += ft_putspaces(flags->spacesright,
				save[i], len_spaces, flags->neg);
	ft_putwstr(s, flags, len_spaces);
	if (flags->minus > 0)
		count += ft_putspaces(flags->spacesleft,
				save[i], len_spaces, flags->neg);
	count += len_spaces;
	return (count);
}
