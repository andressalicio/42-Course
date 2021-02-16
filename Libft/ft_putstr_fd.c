/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:35:49 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:35:49 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"


void	ft_putstr_fd(char *s, int fd)
{
	int i;
    
    if (s != NULL)
    {
        i = 0;
        while (s[i])
        {
            ft_putchar_fd(s[i], fd);
            i++;
        }
    }
}