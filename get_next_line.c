/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yemoreno <yemoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:50:57 by yemoreno          #+#    #+#             */
/*   Updated: 2023/09/26 11:50:57 by yemoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Reads the BUFFER_SIZE bytes into a buffer
NULL if end of file or error*/
char	*read_file(int fd, char *res);
/*Returns the next line in buffer
Empties the buffer when it gives the last line
NULL if empty buffer*/
char	*ft_line(char *buffer, long next);

/*Gets the next line to read in a file.*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	static long	next;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!next)
		next = 0;
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		buffer = read_file(fd, buffer);
	}
	line = ft_line(buffer, next);
	if (!buffer[next])
		free(buffer);
	return (line);
}

char	*read_file(int fd, char *res)
{
	int		read_count;

	read_count = 0;
	read_count = read(fd, res, BUFFER_SIZE);
	if (read_count == -1 || read_count == 0)
	{
		free(res);
		return (NULL);
	}
	res[read_count] = '\0';
	return (res);
}

char	*ft_line(char *buffer, long next)
{
	char		*result;
	long		i;

	if (!buffer)
		return (NULL);
	if (!next)
		next = 0;
	i = 0;
	while (buffer[i + next] && buffer[i + next] != '\n')
		i++;
	result = ft_substr(buffer, next, i);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	if (!buffer[next])
		next = 0;
	else
		next += i + 1;
	return (result);
}
