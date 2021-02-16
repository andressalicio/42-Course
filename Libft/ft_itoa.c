/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:34:32 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:34:32 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int len(long nb)
{
    int len;

    if (nb < 0)
    {
        nb = nb * -1;
        len++;
    }
    while (nb > 0)
    {
        nb = nb / 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int nb)
{
    char *str;
    long n;
    int i;

    n = nb;
    i = len(n);
    if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    str[i--] = '\0';
    if (n == 0)
    {
        str[0] = 48;
        return (str);
    }
    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    while (n > 0)
    {
        str[i] = 48 + (n % 10);
        n = n / 10;
        i--;
    }
    return (str);
}

int main(void)
{
	printf("%s\n", ft_itoa(-123156));
	return (0);
}

/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/