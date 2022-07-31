/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:05:25 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/18 11:35:14 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_int_to_str_base(int nbr, char *base);

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

int	ft_find_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nbr;
	int	i;
	int	char_index;

	sign = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	char_index = ft_find_index(base, str[i]);
	while (char_index != -1)
	{
		nbr = nbr * ft_strlen(base) + char_index;
		char_index = ft_find_index(base, str[++i]);
	}
	return (sign * nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbr_base10;

	if (!ft_is_base_valid(base_from) || !ft_is_base_valid(base_to))
		return (NULL);
	nbr_base10 = ft_atoi_base(nbr, base_from);
	return (ft_int_to_str_base(nbr_base10, base_to));
}
