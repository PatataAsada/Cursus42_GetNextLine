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
/*Used in ft_read_file.
Appends next BUFFER_SIZE bytes read to buffer.
Clears old buffer and returns a new one.*/
char	*ft_free(char *old_buffer, char *append);
/*Removes the first line in buffer
Frees the buffer if it's the last line*/
char	*ft_next(char *old_buffer);
/*Returns the next line in buffer
Empties the buffer when it gives the last line
NULL if empty buffer*/
char	*ft_line(char *buffer);

/*Gets the next line to read in a file.*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	line = ft_line(buffer);
	if (!line)
		free(line);
	buffer = ft_next(buffer);
	return (line);
}

char	*read_file(int fd, char *result)
{
	int		read_count;
	char	*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_count = 1;
	while (read_count > 0 && ft_strchr(result, '\n') == NULL)
	{
		read_count = read(fd, tmp, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(tmp);
			free(result);
			return (NULL);
		}
		tmp[read_count] = 0;
		result = ft_free(result, tmp);
	}
	free(tmp);
	return (result);
}

char	*ft_line(char *buffer)
{
	char		*result;
	long		i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (result = ft_substr(buffer, 0, i));
}

char	*ft_free(char *old_buffer, char *append)
{
	char	*temp;

	temp = ft_strjoin(old_buffer, append);
	if (old_buffer)
		free(old_buffer);
	return (temp);
}

char	*ft_next(char *old_buffer)
{
	char	*tmp;
	int		i;

	if (!old_buffer)
		return (NULL);
	i = 0;
	while (old_buffer[i] && old_buffer[i] != '\n')
		i++;
	if (!old_buffer[i] || !old_buffer[i + 1])
	{
		free(old_buffer);
		return (NULL);
	}
	tmp = ft_substr(old_buffer, i + 1, BUFFER_SIZE);
	free(old_buffer);
	return (tmp);
}
