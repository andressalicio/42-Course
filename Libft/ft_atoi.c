/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:13:58 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:13:58 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_atoi(char *str)
{
	int neg;
    int res;

    neg = 1;
    res = 0;
    while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' || *str == '\f' || *str == '\r'))
        ++str;
    if (*str == '-')
        neg = -1;
    if (*str == '+' || *str == '-')
        ++str;
    while (*str && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - 48);
        ++str;
    }
    return (neg * res);
}

int main()
{
    char str[10] = {"12345"};

    printf("%d", ft_atoi(str));
}