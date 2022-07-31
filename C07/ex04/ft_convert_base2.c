/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:05:27 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/18 11:35:16 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str);

int	ft_get_int_length(int nbr, int base_len)
{
	if (nbr < 0)
		return (2 + ft_get_int_length(-(nbr / base_len), base_len));
	if (nbr >= base_len)
		return (1 + ft_get_int_length(nbr / base_len, base_len));
	return (1);
}

unsigned int	ft_get_divider(unsigned int nb, unsigned int base_len)
{
	unsigned int	divider;

	divider = 1;
	while (nb / divider >= base_len)
		divider *= base_len;
	return (divider);
}

unsigned int	ft_abs(int nbr)
{
	unsigned int	nb;

	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	return (nb);
}

char	*ft_int_to_str_base(int nbr, char *base)
{
	char			*str;
	unsigned int	base_len;
	unsigned int	nb;
	unsigned int	divider;
	int				i;

	base_len = ft_strlen(base);
	str = (char *)malloc((ft_get_int_length(nbr, base_len) + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	i = 0;
	if (nbr < 0)
		str[i++] = '-';
	nb = ft_abs(nbr);
	divider = ft_get_divider(nb, base_len);
	while (divider > 0)
	{
		str[i++] = base[nb / divider];
		nb = nb % divider;
		divider /= base_len;
	}
	str[i] = '\0';
	return (str);
}
