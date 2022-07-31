/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:04:39 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/23 17:20:31 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_open_file(const char *path)
{
	return (open(path, O_RDONLY));
}

int	ft_close_file(int fd)
{
	return (close(fd));
}

int	ft_lines_count(const char *path)
{
	int		fd;
	char	buffer[BUFSIZ];
	int		bytes_read;
	int		lines_count;
	int		i;

	fd = ft_open_file(path);
	if (fd == -1)
		return (-1);
	lines_count = 0;
	bytes_read = read(fd, buffer, BUFSIZ);
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				lines_count++;
			i++;
		}
		bytes_read = read(fd, buffer, BUFSIZ);
	}
	lines_count++;
	ft_close_file(fd);
	return (lines_count);
}
