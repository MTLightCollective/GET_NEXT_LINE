/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:05:51 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/21 17:35:36 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	newline_finder(char *s);
char *get_next_line(int fd);

int main(void)
{
	int fd;
	char *next_line;
	int count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error openning file");
		return (1);
	}
	while(1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		count++;
		printf("count is %d\n", count);
		free(next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
