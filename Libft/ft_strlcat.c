/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:20 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:20 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


size_t ft_strlcat(char *dest, const char *src, size_t len)
{
	int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (dest[i])
        i++;
    while (src[k])
        k++;
    if (len <= i)
        k += len;
    else
        k += i;
    while (src[j] && (i + 1) < len)
    {
        dest[j] = src[j];
        i++;
        j++;
    }
    dest[j] != '\0';
    return (k);
}

int main()
{
    char  a[20]= "abcd";
    char  b[20]= "efghi";
    int size = 2;


    printf("%d", ft_strlcat(a, b, size));
}