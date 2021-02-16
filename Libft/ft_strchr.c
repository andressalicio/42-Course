/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:06 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:06 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *chr;

	chr = (char *)s;
	while (*chr != c)
	{
		if(!*chr)
			return (NULL);
		chr++;

	}
	return (chr);
}

int main(){

    char palavra[50] = {"abacate"};
    char letra = 'b';

    // primeira ocorrência da letra  
   
    printf("%c\n%s\n", letra, ft_strchr(palavra, letra));
    
}
