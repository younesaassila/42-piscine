/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:16:44 by asaleem           #+#    #+#             */
/*   Updated: 2022/07/17 15:18:40 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	*get_clues_from_input(char *input)
{
	int	i;
	int	j;
	int	*clues;

	clues = malloc(16 * sizeof(int));
	if (clues == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		if ('0' <= input[i] && input[i] <= '9')
		{
			clues[j] = ft_atoi(input + i);
			j++;
		}
		i++;
	}
	return (clues);
}
