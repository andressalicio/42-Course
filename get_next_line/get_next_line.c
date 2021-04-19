/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:20:38 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/02 22:07:38 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_save(char *save)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;	
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n' )
		i++;	
	if (!save[i])
	{		
		free(save);		
		return (0);
	}	
	if (!(result = malloc(sizeof(char) * ( (ft_strlen(save) - i) + 1))))
		return (NULL);	
	i++;	
	while (save[i])
	{
		result[j++] = save[i++];
		
	}	
	result[j] = '\0';
	free(save);	
	return (result);
}

char	*get_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (NULL);	
	while (str[i] && str[i] != '\n')
		i++;
	if (!(result = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];		
		i++;		
	}	
	result[i] = '\0';
	return (result);	
}

int		get_next_line(int fd, char **line)
{
	static char	*save[10000];
	char		*buff;
	int			reader;

	reader = 1;	
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);	
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (reader != 0 && !has_return(save[fd]))
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}	
		buff[reader] = '\0';
		save[fd] = join_str(save[fd], buff);	
	}	
	free(buff);
	*line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	if (reader == 0)
		return (0);
	return (1);
}
