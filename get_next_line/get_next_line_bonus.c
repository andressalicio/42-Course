/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:19:24 by ande-sou          #+#    #+#             */
/*   Updated: 2021/02/25 14:19:24 by ande-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
// #include "get_next_line_utils.c"
#include "get_next_line_bonus.h"

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

/*int		main(int argc, char **argv)
{
	int		fd[argc];
	int		ret[argc];
	char	*str;
	int		are_all_files_read;
	int		i;

	are_all_files_read = 0;
	i = 0;
	if (argc == 1)
	{
		
		fd[0] = open("test", O_RDWR);
		//printf("fd %d\n", fd[0]);
		while (ret[0])
		{
			ret[0] = get_next_line(fd[0], &str);
			printf("%s\n", str);
			free(str);
		}
	}
	while (i < argc - 1)
	{
		fd[i] = open(argv[i + 1], O_RDWR);
		i++;
	}
	i = 0;
	while (!are_all_files_read)
	{
		while (i < argc - 1)
		{
			ret[i] = get_next_line(fd[i], &str);
			printf("%d-%s\n", ret[i], str);
			free(str);
			i++;
		}
		are_all_files_read = 1;
		while (i)
		{
			i--;
			if (ret[i])
				are_all_files_read = 0;
		}
	}
	return (0);
}

*/