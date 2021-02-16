/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:35:58 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/16 16:35:58 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int i;
    int trigger;

    trigger = 0;
    i = 0;
   while (*str)
   {
       if (*str != c && trigger == 0)
       {
           trigger = 1;
           i++;
       }
       else if (*str == c)
            trigger = 0;
       str++;
   }
   return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char *word;
    int i;

    i = 0;
    word = (char *)malloc((start - finish) * sizeof(char));
    while (start < finish)
        word[i++] = str[start++];
    word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.
*/