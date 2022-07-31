/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:09:36 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:48:00 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/string_utils.h"
#include <stdlib.h>

void	ft_free_dict(t_dict *dict)
{
	int	i;

	i = -1;
	while (dict[++i].key != 0)
	{
		free(dict[i].key);
		free(dict[i].value);
	}
	free(dict);
}
