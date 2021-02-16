/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:25:36 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:25:36 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t  i;
    unsigned char   *ptr;

    i = 0;
    ptr = (unsigned char *)s;
    while(i < n)
    {
        *ptr = (unsigned char)c;
        i++;
        ptr++;
    }
    return (s);
}

int main()
{
    char s[20] = {"andressa"};
    int c = '1';
    size_t n = 3;

    printf("%s", ft_memset(s, c, n));
}
//copia o c para os n primeiros de s;
