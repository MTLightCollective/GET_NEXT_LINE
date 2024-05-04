/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:33:52 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/04 15:08:32 by mamauss          ###   ########.fr       */
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
		return (NULL);
	return (buffer);
}

static char	*stash_cleaner(char *stash)
{
	int			i;
	int			j;
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
		if(!clean_stash)
			free(clean_stash);
		printf("le cleanstash est %p\n", clean_stash);
		while (stash[++i] != '\0')
		{
			clean_stash[j++] = stash[i];
		}
		clean_stash[j] = '\0';
		free (stash);
		return (clean_stash);
	}
	return (stash);
}

char	*if_newline(char *stash, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (newline_finder(stash) == 1)
	{
		while (stash[i] != '\n')
		{
			i++;
		}
		line = malloc((i) * sizeof(char));
		while (j < i)
		{
			line[j] = stash[j];
			j++;
		}
		line[j] = '\n';
		line[j + 1] = '\0';
		printf("le stash dans newline est %p\n", stash);
		printf("le line dans newline est %p\n", line);
		return (line);
	}
	return (free(line), NULL);
}

char	*if_endfile(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc((ft_strlen(stash) + 1) * sizeof(char));
	printf("le line dans endfile est %p\n", line);
	while (stash[i] != '\0')
	{
	line[i] = stash[i];
		i++;
	}
	free (stash);
	stash = NULL;
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	while (line == NULL)
	{
		buffer = read_file(fd);
		stash = ft_strjoin(stash, buffer);
		if (!buffer && newline_finder(stash) != 1)
		{
			if (stash == NULL || *stash == '\0')
				return (free(line), NULL);
			else if (stash != NULL && *stash != '\0')
				line = if_endfile(stash);
		}
		line = if_newline(stash, line);
		stash = stash_cleaner(stash);
	}
	printf("le buffer est %p\n", buffer);
	printf("le stash est %p\n", stash);
	printf("le line est %p\n", line);
	return (line);
}
