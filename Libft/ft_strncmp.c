/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:37 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:37 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t  i;

    if (n == 0)
        return (0);
    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
    {
        ++i;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(){

    char s1[50] = {"abacatese"};
    char s2[10]=  {"abacates"};
    int size = 9;    
   
    printf("%s\n%d\n", s2, ft_strncmp(s1, s2, size));
    
}