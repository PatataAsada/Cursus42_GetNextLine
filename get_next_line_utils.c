/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yemoreno <yemoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:51:20 by yemoreno          #+#    #+#             */
/*   Updated: 2023/09/26 11:51:20 by yemoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	tmp = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i++] = s2[j++];
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*position;

	position = s;
	while (*position != '\0')
	{
		if (*position == (char) c)
			return ((char *) position);
		position++;
	}
	if (*position == (char) c)
		return ((char *) position);
	return (NULL);
}

void	ft_bzero(void *pointer, size_t n)
{
	unsigned char	*pointer_pointer;

	pointer_pointer = pointer;
	while (n-- > 0)
	{
		*(pointer_pointer++) = '\0';
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_bzero (pointer, count * size);
	return (pointer);
}

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
