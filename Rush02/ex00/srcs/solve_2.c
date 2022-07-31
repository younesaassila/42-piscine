/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:05:02 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:48:20 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/solve.h"
#include "../includes/string_utils.h"
#include <stdlib.h>

char	*ft_get_result_zero(t_dict *dict)
{
	char	*str;

	str = ft_dict_get(dict, "0");
	if (!str)
		return (0);
	return (ft_strtrim(str));
}

char	*ft_dgt_chars_to_str(char c1, char c2)
{
	char	*str;

	str = (char *)malloc(3 * sizeof(char));
	if (!str)
		return (0);
	str[0] = c1;
	str[1] = c2;
	str[2] = '\0';
	return (str);
}

char	*ft_join_dgt_str(t_dict *dict, char *str, char *dgt_str,
		int is_hundreds)
{
	char	*strs[3];
	int		size;

	if (!str)
		return (0);
	strs[0] = str;
	strs[1] = ft_dict_get(dict, dgt_str);
	free(dgt_str);
	if (!strs[1])
		return (0);
	size = 2;
	if (is_hundreds)
	{
		strs[2] = ft_dict_get(dict, "100");
		if (!strs[2])
			return (0);
		size++;
	}
	str = ft_strjoin(size, strs, " ");
	return (str);
}
