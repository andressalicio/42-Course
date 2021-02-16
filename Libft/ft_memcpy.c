/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:35:10 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:35:10 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned    char    *ptr1;
    unsigned    char    *ptr2;
    size_t              i;

    i = 0;
    ptr1 = (unsigned char *)dest;
    ptr2 = (unsigned char *)src;
    while (i < n)
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
        i++;
    }
    return (dest);
}

int main()
{
    char    dest[20] = {"andressa"};
    char    src[20] = {"Ermesom"};
    size_t n = 3;

    printf("%s", ft_memcpy(dest, src, n));
}
//retorno: Ermressa. copia n de src para os n primeiros de dest.