/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:33:52 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/15 09:45:35 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
void *ft_calloc(size_t count, size_t size);

void	print_newline_helper(char *buffer)
{
	while (*buffer && *buffer != '\0')
	{
		if(*buffer == '\n')
		{
			*buffer = '\\';
		}
		printf("%c", *buffer);
		buffer++;
	}
}

static char	*read_file(int fd)
{	
	int	bytes_read;
	char	*buffer;
	int count;

	count = 1;	
	printf("ft_calloc[%d]---", count++);
	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	print_newline_helper(buffer);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*gnl_buffer;

	gnl_buffer = read_file(fd);
	return(gnl_buffer);
}
