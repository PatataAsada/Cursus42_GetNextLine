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

/*Searchs in given string for the first aparition
of searched_char*/
char	*ft_strchr(const char *string, int searched_char );
/*Returns the substring of the given string at the given 
start position with the given length*/
char	*ft_substr(const char *s, unsigned int start, size_t len);
/*Returns a string where it appends s2 to the end of s1*/
char	*ft_strjoin(char const *s1, char const *s2);
/*PP measure tape*/
size_t	ft_strlen(const char *str);

size_t	ft_strlen(const char *str)
{
	int	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		tmp = malloc(1 * sizeof(char));
	}
	else if (len >= ft_strlen(s) - start)
		tmp = malloc((ft_strlen(s) + 1 - start) * sizeof(char));
	else
		tmp = malloc((len + 1) * sizeof(char));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	if (!sizetotal)
		return (NULL);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	str = (char *)string;
	if (!string)
		return (NULL);
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	return (NULL);
}
