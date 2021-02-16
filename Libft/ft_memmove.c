/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:35:24 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:35:24 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned    char *ptr1;
    unsigned    char *ptr2;
    size_t i;

    ptr1 = (unsigned char*)dst;
    ptr2 = (unsigned char*)src;
    if (src < dst)
    {
        i = len;
        while (i-- > 0)
        {
            *ptr1 = *ptr2;
            ptr1++;
            ptr2++;
            
        }
    }
    else
    {
        i = 0;
        while(i < len)
        {
            *ptr1 = *ptr2;
            ptr1++;
            ptr2++;
            i++;
        }
    }
    return (dst);
}

int main()
{
    char    dest[20] = {"andressa"};
    char    src[20] = {"Ermesom"};
    size_t n = 3;

    printf("%s", ft_memmove(dest, src, n));
}
//retorno: Ermressa - copia n bytes da área de memória src para a área de memória dest;