/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:37:44 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:37:44 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdio.h>
#include "libft.h"

int ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);

}

int main()
{
    char  c = 'F';

    printf("%c", ft_toupper(c));
}