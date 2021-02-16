/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:34:45 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:34:45 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr1[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		++i;
	}
	return (NULL);
}


int main()
{
    char    dest[20] = {"andressa"};
    char    src[20] = {"ermesom"};
    size_t n = 1;

    int c = 'r';

    printf("%s", ft_memccpy(dest, src, c, n));
}
//A função memccpy() retorna um ponteiro para o próximo caractere em dest depois de c, 
//ou NULO se c não foi encontrado nos n primeiros caracteres de src.

