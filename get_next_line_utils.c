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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*tmp;
	int			i;

	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		tmp = ft_calloc(1, sizeof(char));
		return (tmp);
	}
	if (len >= ft_strlen(s) - start)
		tmp = ft_calloc(ft_strlen(s) + 1 - start, sizeof(char));
	else
		tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (len-- > 0 && s[start + i] != '\0')
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
