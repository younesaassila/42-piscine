/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:14:28 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:48:03 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_max_line_len(const char *path)
{
	int		fd;
	int		max_len;
	int		line_len;
	int		bytes_read;
	char	c;

	fd = ft_open_file(path);
	max_len = 0;
	line_len = 0;
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0)
	{
		if (c == '\n')
		{
			max_len = ft_max(line_len, max_len);
			line_len = 0;
		}
		else
			line_len++;
		bytes_read = read(fd, &c, 1);
	}
	max_len = ft_max(line_len, max_len);
	ft_close_file(fd);
	return (max_len);
}

char	*ft_readline(int fd, int max_line_len)
{
	char	*line;
	int		bytes_read;
	char	c;
	int		i;

	line = (char *)malloc((max_line_len + 1) * sizeof(char));
	if (!line)
		return (0);
	bytes_read = read(fd, &c, 1);
	if (bytes_read < 1)
		return (0);
	i = 0;
	while (bytes_read > 0)
	{
		if (c == '\n')
		{
			line[i++] = '\0';
			return (line);
		}
		else
			line[i++] = c;
		bytes_read = read(fd, &c, 1);
	}
	line[i++] = '\0';
	return (line);
}

char	**ft_readlines(const char *path)
{
	int		fd;
	int		max_line_len;
	char	**lines;
	char	*line;
	int		i;

	fd = ft_open_file(path);
	if (fd == -1)
		return (0);
	if (ft_lines_count(path) == -1)
		return (0);
	lines = (char **)malloc((ft_lines_count(path) + 1) * sizeof(char *));
	if (!lines)
		return (0);
	max_line_len = ft_max_line_len(path);
	line = ft_readline(fd, max_line_len);
	i = 0;
	while (line != 0)
	{
		lines[i++] = line;
		line = ft_readline(fd, max_line_len);
	}
	lines[i++] = 0;
	ft_close_file(fd);
	return (lines);
}
