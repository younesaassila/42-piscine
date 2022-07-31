/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:29:26 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/10 10:06:04 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_line(int x, char start, char mid, char end);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	row;

	if (x == 0 || y == 0)
		return ;
	row = 0;
	while (row < y)
	{
		if (row == 0)
			print_line(x, '/', '*', '\\');
		else if (row == y - 1)
			print_line(x, '\\', '*', '/');
		else
			print_line(x, '*', ' ', '*');
		row++;
	}
}

void	print_line(int x, char start, char mid, char end)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar(start);
		else if (col == x - 1)
			ft_putchar(end);
		else
			ft_putchar(mid);
		col++;
	}
	ft_putchar('\n');
}
