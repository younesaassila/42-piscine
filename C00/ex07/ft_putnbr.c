/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:24:32 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/08 12:01:37 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int	divider;
	unsigned int	number;
	unsigned int	digit;

	if (nb == 0)
		return (ft_putchar('0'));
	if (nb < 0)
	{
		number = -nb;
		ft_putchar('-');
	}
	else
		number = nb;
	divider = 1000000000;
	while (number / divider < 1)
		divider /= 10;
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
