/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:52:56 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/13 13:10:48 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;
	unsigned int	divider;
	unsigned char	c;

	if (nb == 0)
		return (ft_putchar('0'));
	if (nb < 0)
	{
		nbr = -nb;
		ft_putchar('-');
	}
	else
		nbr = nb;
	divider = 1000000000;
	while (nbr / divider < 1)
		divider /= 10;
	while (divider > 0)
	{
		c = (nbr / divider) + '0';
		ft_putchar(c);
		nbr = nbr % divider;
		divider /= 10;
	}
}
