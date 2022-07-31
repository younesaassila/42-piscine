/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:31:39 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/13 14:36:01 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_is_base_valid(char *base)
{
	unsigned int	len;
	int				i;
	int				j;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if ((0 <= base[i] && base[i] <= 32) || base[i] == 127)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	unsigned int	divider;
	unsigned char	c;
	unsigned int	base_len;

	if (!ft_is_base_valid(base))
		return ;
	if (nbr < 0)
	{
		nb = -nbr;
		ft_putchar('-');
	}
	else
		nb = nbr;
	base_len = ft_strlen(base);
	divider = 1;
	while (nb / divider >= base_len)
		divider *= base_len;
	while (divider > 0)
	{
		c = base[nb / divider];
		ft_putchar(c);
		nb = nb % divider;
		divider /= base_len;
	}
}
