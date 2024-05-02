/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:33:52 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/02 10:03:41 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	int		bytes_read;
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

static char	*stash_cleaner(char *stash)
{
	int		i;
	int		j;
	static char	*clean_stash;

	i = 0;
	j = 0;
	if (newline_finder(stash) == 1)
	{
		while (stash[i] != '\n')
		{
			i++;
		}
		clean_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
		while (stash[++i] != '\0')
		{
			clean_stash[j++] = stash[i];
		}
		clean_stash[j] = '\0';
		free (stash);
		return (clean_stash);
	}
	else
		return (stash);
}

char	*if_newline(char *stash, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (newline_finder(stash) == 1)
	{
		while (stash[i] != '\n')
		{
			i++;
		}
		line = malloc((i + 2) * sizeof(char));
		while (j < i)
		{
			line[j] = stash[j];
			j++;
		}
		line[j] = '\n';
		line[j + 1] = '\0';
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	while (line == NULL)
	{
		buffer = read_file(fd);
		if (!buffer && (stash == NULL || *stash == '\0'))
		{
				free (buffer);
				return (NULL);
		}
		stash = ft_strjoin(stash, buffer);	
		line = if_newline(stash, line);
		stash = stash_cleaner(stash);
	}
	return (line);
}
