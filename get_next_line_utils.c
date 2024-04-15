/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:21:35 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/15 10:12:50 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
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

//find the size of the file
//make sure you can handle any number of new lines
//make sure the buffer size doesnt affect the behaviour
//make sure any type of buffer works
//dynamically malloc the basin
//return the first newline
//exctract one line even tho the buffer is bigger than it
//skip read until all newlines are extracted
