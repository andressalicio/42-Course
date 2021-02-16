/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:16 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:16 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char    *str;
    int     i;
    int     j;

    str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!s1 || !s2 || !str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        str[i++] = s2[j++];
    }
    str[i] = '\0';
    return (str);
}

//Allocates (with malloc(3)) and returns a new
//string, which is the result of the concatenation
//of ’s1’ and ’s2’