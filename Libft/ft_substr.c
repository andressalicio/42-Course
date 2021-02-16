/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:37:14 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:37:14 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"



char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t  i;
    size_t  j;
    char    *str;

    str = (char*)malloc(sizeof(*s) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (i >= start && j < len)
        {
            str[j] = s[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
    return (str);
}

int main()
{
    char    s[20] = {"andressa"};
    int    start = 0;
    size_t len = 5;

    printf("%s", ft_substr(s, start, len));
}

//The substring begins at index ’start’ and is of maximum size ’len’.