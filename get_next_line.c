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

char	*ft_next(int fd);
int		ft_read_line(char *tmp, int fd);

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (!fd || !BUFFER_SIZE || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_next(fd);
	return (buffer);
}

char	*ft_next(int fd)
{
	char	*tmp;
	int		len;

	ft_realloc(BUFFER_SIZE, sizeof(char), tmp);
	if (!tmp)
		return (NULL);
	len = read(fd, tmp, BUFFER_SIZE);
}
