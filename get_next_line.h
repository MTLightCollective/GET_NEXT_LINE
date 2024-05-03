/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:58:30 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/02 15:22:34 by mamauss          ###   ########.fr       */
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
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
int			newline_finder(char *s);
char		*read_file(int fd);
/*static char		*stash_cleaner(char *stash);*/
char		*if_newline(char *stash, char *line);
char		*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
