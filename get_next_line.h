/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:58:30 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/25 20:42:02 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

int			ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
int			newline_finder(char *s);
char		*read_file(int fd);
char		*stash_cleaner(char *stash);
char		*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
