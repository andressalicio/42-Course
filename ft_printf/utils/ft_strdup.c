/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:22:16 by ande-sou          #+#    #+#             */
/*   Updated: 2021/04/14 11:07:16 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_memcpy(char *dst, const char *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		i++;
	}
	*ptr1 = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		len;

	len = ft_strlen(s1) + 1;
	result = (char *)malloc(sizeof(char *) * len);
	if (!result)
		return (0);
	result = ft_memcpy(result, s1, len);
	return (result);
}
