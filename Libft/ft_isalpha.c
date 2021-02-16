/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:33:05 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:33:05 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z' || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int main()
{
    char c = '2';

    printf("%d", ft_isalpha(c));
}
