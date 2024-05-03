/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:21:35 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/03 19:15:27 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	newline_finder(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	len2;

	len = 0;
	len2 = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	while (src[len2] != '\0' && (len2 < (dstsize - 1)))
	{
		dst[len2] = src[len2];
		len2++;
	}
	if (dstsize != 0)
		dst[len2] = '\0';
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, len1 + 1);
	else
		result[0] = '\0';
	if (s2)
		ft_strlcpy(result + len1, s2, len2 + 1);
	return (free(s1), free(s2), result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*string;
	unsigned char	*bytestring;
	size_t			i;
	size_t			totalsize;

	i = 0;
	totalsize = size * count;
	string = (void *)malloc(totalsize);
	if (!string)
		return (0);
	bytestring = (unsigned char *)string;
	while (i < totalsize)
	{
		bytestring[i] = '\0';
		i++;
	}
	return (string);
}
