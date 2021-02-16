/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:35:02 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:35:02 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned    char *ptr1;
    unsigned    char *ptr2;
    int i;

    i = 0;
    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    if (n == 0)
		return (0);
    while (*ptr1 == *ptr2 && ++i < n)
    {
        ptr1++;
        ptr2++;
    }
    return ((int)(*ptr1 - *ptr2));
}

int main(){

    char s1[50] = {"abacatese"};
    char s2[10]=  {"abacates"};
    int size = 9;    
   
    printf("%s\n%d\n", s2, ft_memcmp(s1, s2, size));
    
}