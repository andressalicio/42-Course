/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:37:14 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/19 15:28:05 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (!(result = malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
