/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:21:35 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/21 18:45:42 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

/*char	*ft_strdup(const char *s1)
{
	char	*newptr;
	int		i;

	i = 0;
	newptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (newptr == NULL)
		return (NULL);
	while (s1[i])
	{
		newptr[i] = s1[i];
		i++;
	}
	newptr[i] = '\0';
	return (newptr);
}*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*answer;
	size_t	total_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	void		*string;
	unsigned char	*bytestring;
	size_t		i;
	size_t		totalsize;

	i = 0;
	totalsize = size * count;
	string = (void *)malloc(totalsize);
	if (!string)
		return (0);
	bytestring = (unsigned char*)string;
	while (i < totalsize)
	{
		bytestring[i] = '\0';
		i++;
	}
	return (string);
}

/*int ft_linejump_finder(char *buffer)
{
	int i;
	
	i = 0;
	while(buffer[i] != '\n')
		i++;
	if (i <= BUFFER_SIZE)
	return (i);
}*/
//find the size of the file
//make sure you can handle any number of new lines
//make sure the buffer size doesnt affect the behaviour
//make sure any type of buffer works
//dynamically malloc the basin
	//calculate the size untill the \n
	//influence the count
//return the first newline

//exctract one line even tho the buffer is bigger than it

//skip read until all newlines are extracted
