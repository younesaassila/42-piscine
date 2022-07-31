/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:44:30 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 16:24:45 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/file_utils.h"
#include "../includes/string_utils.h"
#include <stdlib.h>

t_dict	*ft_create_dict(const char *path)
{
	int		lines_count;
	t_dict	*dict;

	lines_count = ft_lines_count(path);
	dict = (t_dict *)malloc((lines_count + 1) * sizeof(t_dict));
	return (dict);
}

int	ft_parse_dict_line(t_dict *dict, char *line, int index)
{
	char	*dict_key;
	char	*dict_value;

	dict_key = ft_parse_dict_key(line);
	dict_value = ft_parse_dict_value(line);
	if (dict_key == 0 || dict_value == 0)
	{
		dict[index].key = 0;
		dict[index].value = 0;
		return (0);
	}
	dict[index].key = dict_key;
	dict[index].value = dict_value;
	return (1);
}

t_dict	*ft_parse_dict_file(const char *path)
{
	char	**lines;
	t_dict	*dict;
	int		i;
	int		j;

	dict = ft_create_dict(path);
	if (!dict)
		return (0);
	lines = ft_readlines(path);
	if (!lines)
	{
		ft_free_dict(dict);
		return (0);
	}
	i = -1;
	j = 0;
	while (lines[++i] != 0)
	{
		if (ft_strlen(lines[i]) > 0)
			if (!ft_parse_dict_line(dict, lines[i], j++))
				return (0);
	}
	ft_parse_dict_line(dict, "", j++);
	free(lines);
	return (dict);
}
