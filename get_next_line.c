/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:33:52 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/21 18:50:03 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void *ft_calloc(size_t count, size_t size);
int ft_line_sizer(char *buffer);
char	*ft_strjoin(const char *s1, char const *s2);

int	newline_finder(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_file(int fd)
{	
	int	bytes_read;
	char	*buffer;

	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	int i;
	int j;

	i = 0;
	j = 0;
	buffer = read_file(fd);
	stash = ft_strjoin(stash, buffer);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}
	if (newline_finder(stash) == 1)
	{
		line = malloc((i + 1) * sizeof(char));
		while (j <= i && stash != NULL)
		{
			line[j] = stash[j];
			j++;
		}
		line[j] = '\0';
	}
	i = 0;
	j = 0;
	printf("le buffer est: %s\n", buffer);
	printf("la stash est: %s\n", stash);
	printf("le i est: %d\n", i);
	printf("la line est: %s\n", line);
	return(buffer);
}
