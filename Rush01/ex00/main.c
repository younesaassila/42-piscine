/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:11:14 by asaleem           #+#    #+#             */
/*   Updated: 2022/07/17 22:33:31 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	show_error(void)
{
	ft_puterr("Error\n");
	return (1);
}

int	is_input_format_valid(char *input)
{
	int		len;
	int		i;
	char	c;

	len = ft_strlen(input);
	if (len != 31)
		return (0);
	i = 0;
	while (i < len)
	{
		c = input[i];
		if (i % 2 == 0 && !('1' <= c && c <= '4'))
			return (0);
		if (i % 2 == 1 && c != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	fill_tab(int tab[4][4], int value)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = value;
			j++;
		}
		i++;
	}
}

void	print_tab(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != 0)
				ft_putchar(' ');
			ft_putnbr(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	tab[4][4];
	int	*clues;

	if (argc != 2 || !is_input_format_valid(argv[1]))
		return (show_error());
	fill_tab(tab, 0);
	clues = get_clues_from_input(argv[1]);
	if (!clues)
		return (show_error());
	if (solve(tab, clues, 0))
	{
		free(clues);
		print_tab(tab);
		return (0);
	}
	else
		return (show_error());
}
