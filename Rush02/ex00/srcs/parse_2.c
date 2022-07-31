/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:02:14 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:48:13 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/string_utils.h"
#include <stdlib.h>

int	ft_keylen(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ':' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	return (i);
}

char	*ft_create_key(char *line)
{
	int		len;
	char	*key;

	len = ft_keylen(line);
	if (!len)
		return (0);
	key = (char *)malloc((len + 3) * sizeof(char));
	return (key);
}

char	*ft_parse_dict_key(char *line)
{
	char	*key;
	int		i;
	int		j;

	key = ft_create_key(line);
	if (!key)
		return (0);
	i = 0;
	j = 0;
	while (whitespace(line[i]))
		i++;
	if (line[i] == '+' || line[i] == '-')
		if (line[i++] == '-')
			key[j++] = '-';
	if (!('0' <= line[i] && line[i] <= '9'))
		return (0);
	while (line[i] == '0')
		i++;
	while ('0' <= line[i] && line[i] <= '9')
		key[j++] = line[i++];
	if (j == 0 || !('0' <= key[j - 1] && key[j - 1] <= '9'))
		key[j++] = '0';
	key[j++] = '\0';
	return (key);
}

char	*ft_parse_dict_value(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ':' && line[i] != '\0')
		i++;
	if (line[i] == ':')
		i++;
	else
		return (0);
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	return (ft_strtrim(line + i));
}
