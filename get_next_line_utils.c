/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:21:35 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/25 19:20:56 by mamauss          ###   ########.fr       */
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*answer;
	size_t	total_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s2 == NULL)
	{
		total_len = ft_strlen(s1) + 1;
		answer = malloc(sizeof(char) * total_len);
		while (s1[i] != '\0')
		{
			answer[i] = s1[i];
			i++;
		}
		answer[i] = '\0';
		return (answer);
	}
	if (s1 == NULL)
	{
		answer = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		while (s2[i] != '\0')
		{
			answer[i] = s2[i];
			i++;
		}
		answer[i] = '\0';
		return (answer);
	}
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	answer = malloc(sizeof(char) * total_len);
	if (!answer)
		return (NULL);
	while (s1[i] != '\0')
	{
		answer[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		answer[i + j] = s2[j];
		j++;
	}
	answer[i + j] = '\0';
	return (answer);
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
