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

/**
 * @brief	Reads BUFFER_SIZE bytes of file
 * 			until it reaches a new line.
 * @return	Buffer with the bytes read from file.
 * 			NULL if EOF or Error.
 * @param	int	fd : file descriptor.
 * @param	char	*res: buffer to
*/
char	*read_file(int fd, char *res);
/**
 * @brief	Creates a string of the old buffer and the
 * 			string to append, and clears the old buffer.
 * @return	New String resulting of joining old_buffer and append
 * @param	char	*old_buffer : the starting string.
 * @param	char	*append : the string to join.
 */
char	*ft_free(char *old_buffer, char *append);
/**
 * @brief	Deletes the n charachters in string until 
 * 			it reaches new line or end of string.
 * @return	New String with N chars removed.
 * 			NULL if it can't find new line.
 * @param	char	*old_buffer : the buffer to modify.
 */
char	*ft_next(char *old_buffer);
/**
* @brief	Gives the first line in given buffer.
* @return	The first String from Buffer.
* @param	char	*buffer : A String that may contain new lines.
*/
char	*ft_line(char *buffer);

/**
 * @brief	Reads a line from a file descriptor and returns it as a string.
 * @return	A pointer to the string containing the line read from the file.
 * @param	int		fd : The file descriptor to read from.
 */
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
		free(line);
	buffer = ft_next(buffer);
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	int		read_count;
	char	*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_count = 1;
	while (read_count > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		read_count = read(fd, tmp, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(tmp);
			if (buffer)
				free(buffer);
			return (NULL);
		}
		if (!tmp)
			break ;
		tmp[read_count] = '\0';
		buffer = ft_free(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	long	i;
	char	*tmp;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			break ;
	tmp = ft_substr(buffer, 0, i);
	if (!tmp)
		free(tmp);
	return (tmp);
}

char	*ft_free(char *old_buffer, char *append)
{
	char	*temp;

	if (!old_buffer && !append)
		return (NULL);
	temp = ft_strjoin(old_buffer, append);
	if (!temp)
		free(temp);
	free(old_buffer);
	return (temp);
}

char	*ft_next(char *old_buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!old_buffer)
		return (NULL);
	while (old_buffer[i] && old_buffer[i] != '\n')
		i++;
	if (old_buffer[i] == '\n')
		i++;
	if (!old_buffer[i])
	{
		free(old_buffer);
		return (NULL);
	}
	tmp = ft_substr(old_buffer, i, ft_strlen(old_buffer));
	free(old_buffer);
	if (!tmp)
		return (NULL);
	return (tmp);
}
