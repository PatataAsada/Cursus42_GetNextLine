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

/*Moves to the next line in buffer*/
char	*ft_next(char *buffer);
/*frees the buffer and replaces with new buf*/
char	*ft_replace(char *buffer, char *buf);
/*Reads the BUFFER_SIZE bytes into a buffer*/
char	*read_file(int fd, char *res);
/*returns the first line in buffer*/
char	*ft_line(char *buffer);

/*Gets the next line to read in a file.*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	free(buffer);
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*tmp;
	int		read_count;

	read_count = 1;
	while (read_count > 0)
	{
		tmp = ft_calloc(2, sizeof(char));
		if (!tmp)
			return (NULL);
		read_count = read(fd, tmp, 1);
		if (read_count == -1)
		{
			free(tmp);
			return (NULL);
		}
		if (tmp[0] == '\n')
		{
			free (tmp);
			break ;
		}
		if (read_count > 0)
			res = ft_replace(res, tmp);
		free(tmp);
	}
	return (res);
}

char	*ft_line(char *buffer)
{
	char	*tmp;

	tmp = ft_calloc(ft_strlen(buffer), sizeof(char));
	if (!tmp)
		return (NULL);
	return (ft_strjoin(buffer, tmp));
}

char	*ft_replace(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
