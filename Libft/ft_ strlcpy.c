/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:10:44 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/09 16:10:44 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  sizesrc;

    sizesrc = 0;
    while (src[sizesrc])
        sizesrc++;
    
    i = 0;
    while (src[i] != '\0' && i < (size - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] != '\0';
    return (sizesrc);
}

int main()
{
    char  a[20]= "abcd";
    char  b[20]= "ef";
    int size = 3;


    printf("%d", ft_strlcpy(a, b, size));
}