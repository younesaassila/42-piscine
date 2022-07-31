/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:11:39 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/17 22:49:52 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_double(int tab[4][4], int pos, int num)
{
	int	i;

	i = -1;
	while (++i < pos / 4)
		if (tab[i][pos % 4] == num)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (tab[pos / 4][i] == num)
			return (1);
	return (0);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}
