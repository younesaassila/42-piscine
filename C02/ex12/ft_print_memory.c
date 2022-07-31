/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:51:41 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/11 16:07:28 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	ft_print_line(unsigned char *ptr, unsigned int line_size);
void	ft_putnbr(unsigned long nbr, int digit_count);
long	ft_pow(int base, int exponent);
void	ft_putchar(char c);

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				lines;
	int				line;
	unsigned int	line_size;
	unsigned char	*ptr;

	lines = size / 16;
	if (size % 16 > 0)
		lines++;
	line = 0;
	while (line < lines)
	{
		line_size = 16;
		if (line == lines - 1 && size % 16 > 0)
			line_size = size % 16;
		ptr = addr;
		ft_putnbr((unsigned long)ptr + line * 16, 16);
		ft_putchar(':');
		ft_putchar(' ');
		ft_print_line(ptr + line * 16, line_size);
		ft_putchar('\n');
		line++;
	}
	return (addr);
}

void	ft_print_line(unsigned char *ptr, unsigned int line_size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < line_size)
			ft_putnbr(ptr[i], 2);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < line_size)
	{
		if (32 <= ptr[i] && ptr[i] <= 126)
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	ft_putnbr(unsigned long nbr, int digit_count)
{
	unsigned long	divider;
	unsigned long	number;
	unsigned long	digit;
	int				i;

	number = nbr;
	if (number == 0)
	{
		i = 0;
		while (i++ < digit_count)
			ft_putchar('0');
		return ;
	}
	divider = ft_pow(16, digit_count - 1);
	while (divider > 0)
	{
		digit = number / divider;
		if (digit < 10)
			ft_putchar(digit + '0');
		else
			ft_putchar(digit - 10 + 'a');
		number = number % divider;
		divider /= 16;
	}
}

long	ft_pow(int base, int exponent)
{
	long	temp;

	if (exponent == 0)
		return (1);
	if (exponent % 2 == 0)
	{
		temp = ft_pow(base, exponent / 2);
		return (temp * temp);
	}
	else
		return (base * ft_pow(base, exponent - 1));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}
