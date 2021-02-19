/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:20 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/19 15:10:42 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen((char*)src);
	j = ft_strlen(dest);
	if(j >= len)
		return (len + i);
	if (i < (len - j))
	{
		ft_memcpy(dest + j, src, i);
		dest[j + i] = '\0';
	}
	else
	{
		ft_memcpy(dest + j, src, len - j - 1);
		dest[len - 1] = '\0';
	}
	return (j + i);
}
