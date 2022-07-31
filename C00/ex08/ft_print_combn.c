/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:30:04 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/08 12:53:32 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
int		ft_get_max_number(int n);
int		ft_is_num_valid(int nb, int divider, int prev_digit);
void	ft_print_num(int nb, int max_divider);
void	ft_putchar(char c);

void	ft_print_combn(int n)
{
	int	max_number;
	int	max_divider;
	int	number;
	int	divider;
	int	is_valid;

	max_number = ft_get_max_number(n);
	max_divider = 1000000000;
	while (max_number / max_divider < 1)
		max_divider /= 10;
	number = 1;
	while (number < max_number + 1)
	{
		divider = 1000000000;
		while (number / divider < 1)
			divider /= 10;
		is_valid = ft_is_num_valid(number, divider, 0);
		if (is_valid)
			ft_print_num(number, max_divider);
		number++;
	}
}

int	ft_get_max_number(int n)
{
	int	result;
	int	i;
	int	j;
	int	number;

	result = 0;
	i = 0;
	while (i < n)
	{
		number = (9 - i);
		j = i;
		while (j > 0)
		{
			number *= 10;
			j--;
		}
		result += number;
		i++;
	}
	return (result);
}

int	ft_is_num_valid(int nb, int divider, int prev_digit)
{
	int	digit;

	digit = nb / divider;
	if (digit > prev_digit)
	{
		if (nb > 9)
			return (ft_is_num_valid(nb % divider, divider / 10, digit));
		else
			return (1);
	}
	else
		return (0);
}

void	ft_print_num(int nb, int max_divider)
{
	int	divider;
	int	number;
	int	digit;

	divider = max_divider;
	number = nb;
	if (number == 0)
		return (ft_putchar('0'));
	if (number != 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (number / divider < 1)
	{
		divider /= 10;
		ft_putchar('0');
	}
	while (divider > 0)
	{
		digit = number / divider;
		ft_putchar(digit + 48);
		number = number % divider;
		divider /= 10;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}
