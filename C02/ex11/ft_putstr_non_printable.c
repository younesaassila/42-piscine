/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:37:25 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/11 14:24:37 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_printable(unsigned char c);
void	ft_putnbr_hex(unsigned int nbr);
void	ft_putdigit_hex(unsigned int digit);
void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (ft_is_printable(c))
			ft_putchar(c);
		else
		{
			ft_putchar('\\');
			ft_putnbr_hex(c);
		}
		i++;
	}
}

int	ft_is_printable(unsigned char c)
{
	if ((32 <= c && c <= 126))
		return (1);
	else
		return (0);
}

void	ft_putnbr_hex(unsigned int nbr)
{
	unsigned int	number;
	unsigned int	digit1;
	unsigned int	digit2;

	number = nbr;
	digit1 = number / 16;
	digit2 = number % 16;
	ft_putdigit_hex(digit1);
	ft_putdigit_hex(digit2);
}

void	ft_putdigit_hex(unsigned int digit)
{
	if (digit < 10)
		ft_putchar(digit + '0');
	else
		ft_putchar(digit - 10 + 'a');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}
