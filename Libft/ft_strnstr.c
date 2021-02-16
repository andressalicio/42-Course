/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:48 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:36:48 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


char	*ft_strnstr(const char *big, const char *little, int len)
{
	int i;
    char *plittle;
    char *pbig;

    if (!*little)
        return ((char *)big);
    while (len-- && *big)
    {
        if (*big == *little)
        {
            i = len;
             pbig = (char *)big + 1;
            plittle = (char *)little + 1;
           
            while (i-- && *pbig && *plittle && *plittle == *pbig)
            {

                ++plittle;
                ++pbig;
                
            }
            if (*plittle == '\0')
                return ((char *)big);
          
        }
        big++;
    }
    return (NULL);
}


int main(){

    char big[50] = {"abacate"};
    char li[5]=  {"ca"};
    int size = 7;    
   
    printf("%s\n%s\n", li, ft_strnstr(big, li, size));
    
}