/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:43:35 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/03 17:17:07 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("line found : %s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	if (str == NULL)
	{
		printf("its NULL : %s\n", str);
		str = NULL;
		free(str);
	}
	close(fd);
}
