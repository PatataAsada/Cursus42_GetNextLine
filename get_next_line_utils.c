/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yemoreno <yemoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:51:20 by yemoreno          #+#    #+#             */
/*   Updated: 2023/10/07 14:08:47 by yemoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief	The length of given string.
 * @return	The length of the string.
 * 			NULL if nothing given.
 * @param	char	*str : the string to measure.
 */
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

/**
 * @brief	Given a string, it takes len characters from the position
 * 			given.
 * @return	A substring of the given string with the parameters given.
 * 			NULL if any error.
 * @param	char	*s : The original string to work.
 * @param	int		start : The position where to start the substring.
 * @param	size_t	len : The desired length of the substring.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*temp;
	int			i;

	i = 0;
	if (!s || ft_strlen(s) < start || len <= 0 || start < 0)
		return (NULL);
	if (len >= ft_strlen(s) - start)
	{
		temp = malloc((ft_strlen(s) + 1 - start) * sizeof(char));
	}
	else
		temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (len-- > 0 && s[start + i] != '\0')
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/**
 * @brief	Join two strings into one.
 * @return	String resulted from joining the 2 given strings.
 * 			NULL if error.
 * @param	char	*s1 : the first string.
 * @param	char	*s2 : the string to join to s1.
 */
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

/**
 * @brief	Searchs in given string for the first aparition
 * 			of searched_char.
 * @return	Pointer of string from first aparition of seached_char
 * 			in string given.
 * 			NULL if any error or not found.
 * @param	char	*string : where we will search.
 * @param	int		searched_char : the char we are searching for.
 */
char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	if (!string)
		return (NULL);
	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	return (NULL);
}
