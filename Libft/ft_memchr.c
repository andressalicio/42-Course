/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:34:54 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:34:54 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    unsigned    char *ptr;
    size_t i;

    i = 0;
    ptr = (unsigned char *)s;
    while (i < n)
    {
        if (*ptr == (unsigned char)c)
            return ((void *)ptr);
        ptr++;
        i++;
    }
    return (NULL);
}

int main()
{
    char    s[20] = {"andressa"};
    char    c = 'e';
    size_t n = 5;

    printf("%s", ft_memchr(s, c, n));
}
//retorno; essa. procura nos 'n' primeiros de 's', e retorna o ponteiro de 'c' no 's'';
//A função procura a primeira ocurrência do valor c (0 a 255) nos primeiros count bytes do buffer de memória apontado por buf.  
//Pára quando encontra o primeiro valor c ou quando já examinou count bytes. 
//Retorna um apontador para o local da primeira ocorrência de c ou NULL se não encontrar c.