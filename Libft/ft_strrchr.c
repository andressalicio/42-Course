/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:55 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:55 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


char	*ft_strrchr(const char *s, int c)
{
	char *last_pos;

    last_pos = (0);
    while (*s)
    {
        if (*s == c)
            last_pos = (char *)s;
        ++s;

    }
    if (last_pos)
        return (last_pos);
    if (c == '\0')
        return ((char *)s);
    return (0);

}

int main(){

    char palavra[50] = {"abacate"};
    char letra = 'a';

    // ultima ocorrência da letra  
   
    printf("%c\n%s\n", letra, ft_strrchr(palavra, letra));
    
}