/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:28:49 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:28:49 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *p;

    if (!(p = malloc(nmemb * size)))
        return (NULL);
    ft_bzero(p, nmemb * size);
    return (p);

}

// aloca uma quantidade de mem�ria igual a num * size, isto �, aloca mem�ria suficiente para uma matriz de num objetos de tamanho size. 
//Retorna um ponteiro void * para o primeiro byte alocado. O ponteiro void * pode ser atribu�do a qualquer tipo de ponteiro. 
//Se n�o houver mem�ria suficiente para alocar a mem�ria requisitada a fun��o calloc() retorna um ponteiro nulo.