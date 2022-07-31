/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaleem <asaleem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:16:41 by asaleem          #+#    #+#             */
/*   Updated: 2022/07/17 15:18:29 by asaleem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	solve(int tab[4][4], int clues[16], int pos)
{
	int	size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_double(tab, pos, size) == 0)
		{
			tab[pos / 4][pos % 4] = size;
			if (check_case(tab, pos, clues) == 0)
			{
				if (solve(tab, clues, pos + 1) == 1)
					return (1);
			}
			else
				tab[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}
