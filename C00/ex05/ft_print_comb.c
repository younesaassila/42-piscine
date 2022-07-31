/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:52:27 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/08 09:57:22 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_print_digits(int digit_1, int digit_2, int digit_3);
void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int	digit_1;
	int	digit_2;
	int	digit_3;

	digit_1 = 0;
	while (digit_1 < 10)
	{
		digit_2 = digit_1 + 1;
		while (digit_2 < 10)
		{
			digit_3 = digit_2 + 1;
			while (digit_3 < 10)
			{
				ft_print_digits(digit_1, digit_2, digit_3);
				digit_3++;
			}
			digit_2++;
		}
		digit_1++;
	}
}

void	ft_print_digits(int digit_1, int digit_2, int digit_3)
{
	int	ascii_offset;

	ascii_offset = 48;
	if (!(digit_1 == 0 && digit_2 == 1 && digit_3 == 2))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	ft_putchar(digit_1 + ascii_offset);
	ft_putchar(digit_2 + ascii_offset);
	ft_putchar(digit_3 + ascii_offset);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}
