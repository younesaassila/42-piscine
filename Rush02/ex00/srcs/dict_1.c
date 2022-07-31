/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:55:41 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:47:57 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/string_utils.h"

char	*ft_dict_get(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (dict[i].key != 0)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (0);
}

int	ft_dict_set(t_dict *dict, char *key, char *value)
{
	int	i;

	i = 0;
	while (dict[i].key != 0)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
		{
			dict[i].value = value;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_dict_replace_values(t_dict *dest, t_dict *src)
{
	int	i;

	i = 0;
	while (src[i].key != 0)
	{
		ft_dict_set(dest, src[i].key, ft_strdup(src[i].value));
		i++;
	}
}

int	ft_dict_size(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].key != 0)
	{
		i++;
	}
	return (i);
}

int	ft_dict_key_maxlen(t_dict *dict)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	len = 0;
	while (dict[i].key != 0)
	{
		len = ft_strlen(dict[i].key);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
