/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:21:39 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:57:34 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/solve.h"
#include "../includes/string_utils.h"
#include <stdlib.h>

int	*ft_get_dgt_group(char *input, int i, int len)
{
	int	*dgt_group;

	dgt_group = (int *)malloc(3 * sizeof(int));
	if (!dgt_group)
		return (0);
	if (0 <= i && i < len)
		dgt_group[0] = input[i] - '0';
	else
		dgt_group[0] = 0;
	if (0 <= (i + 1) && (i + 1) < len)
		dgt_group[1] = input[i + 1] - '0';
	else
		dgt_group[1] = 0;
	if (0 <= (i + 2) && (i + 2) < len)
		dgt_group[2] = input[i + 2] - '0';
	else
		dgt_group[2] = 0;
	return (dgt_group);
}

char	*ft_dgt_group_result(t_dict *dict, int dgt1, int dgt2, int dgt3)
{
	char	*str;

	str = "";
	if (dgt1 != 0)
		str = ft_join_dgt_str(dict, str, ft_dgt_chars_to_str(dgt1 + '0', '\0'),
				1);
	if (dgt2 == 1)
		str = ft_join_dgt_str(dict, str, ft_dgt_chars_to_str(dgt2 + '0', dgt3
					+ '0'), 0);
	else
	{
		if (dgt2 > 1)
			str = ft_join_dgt_str(dict, str, ft_dgt_chars_to_str(dgt2 + '0',
						'0'), 0);
		if (dgt3 != 0)
			str = ft_join_dgt_str(dict, str, ft_dgt_chars_to_str(dgt3 + '0',
						'\0'), 0);
	}
	if (!str)
		return (0);
	return (ft_strtrim(str));
}

char	*ft_add_thousands_suffix(t_dict *dict, char *str, int max)
{
	char	*strs[2];
	char	*thousands;
	int		i;

	i = 0;
	thousands = (char *)malloc((ft_dict_key_maxlen(dict) + 2) * sizeof(char));
	if (!thousands)
		return (0);
	thousands[i++] = '1';
	while (i <= max)
		thousands[i++] = '0';
	thousands[i++] = '\0';
	if (i > 2)
	{
		strs[0] = str;
		strs[1] = ft_dict_get(dict, thousands);
		if (!strs[1])
		{
			free(thousands);
			return (0);
		}
		str = ft_strjoin(2, strs, " ");
	}
	free(thousands);
	return (str);
}

char	*ft_join_dgt_group(t_dict *dict, char *str, int *dgt_group, int n)
{
	char	*strs[2];

	strs[0] = str;
	strs[1] = ft_dgt_group_result(dict, dgt_group[0], dgt_group[1],
			dgt_group[2]);
	if (!strs[1])
		return (0);
	str = ft_strjoin(2, strs, " ");
	if (n % 3 == 0)
	{
		str = ft_add_thousands_suffix(dict, str, (n - 3));
		if (!str)
			return (0);
	}
	free(dgt_group);
	return (str);
}

char	*ft_get_result(t_dict *dict, char *input)
{
	char	*str;
	int		*dgt_group;
	int		len;
	int		offset;
	int		i;

	len = ft_strlen(input);
	str = "";
	if (ft_strcmp(input, "0") == 0)
		return (ft_get_result_zero(dict));
	offset = (3 - (len % 3)) % 3;
	i = 0 - offset;
	while (i < len)
	{
		dgt_group = ft_get_dgt_group(input, i, len);
		if (dgt_group && (dgt_group[0] || dgt_group[1] || dgt_group[2]))
		{
			str = ft_join_dgt_group(dict, str, dgt_group, ((len + offset) - (i
							+ offset)));
			if (!str)
				return (0);
		}
		i += 3;
	}
	return (ft_strtrim(str));
}
