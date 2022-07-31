/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:43:13 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/08 10:09:01 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_print_numbers(int num_1, int num_2);
void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int	num_1;
	int	num_2;

	num_1 = 0;
	while (num_1 < 100)
	{
		num_2 = num_1 + 1;
		while (num_2 < 100)
		{
			ft_print_numbers(num_1, num_2);
			num_2++;
		}
		num_1++;
	}
}

void	ft_print_numbers(int num_1, int num_2)
{
	int		ascii_offset;
	char	num_1_dgt_1;
	char	num_1_dgt_2;
	char	num_2_dgt_1;
	char	num_2_dgt_2;

	ascii_offset = 48;
	num_1_dgt_1 = num_1 / 10;
	num_1_dgt_2 = num_1 % 10;
	num_2_dgt_1 = num_2 / 10;
	num_2_dgt_2 = num_2 % 10;
	if (!(num_1 == 0 && num_2 == 1))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	ft_putchar(num_1_dgt_1 + ascii_offset);
	ft_putchar(num_1_dgt_2 + ascii_offset);
	ft_putchar(' ');
	ft_putchar(num_2_dgt_1 + ascii_offset);
	ft_putchar(num_2_dgt_2 + ascii_offset);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}
