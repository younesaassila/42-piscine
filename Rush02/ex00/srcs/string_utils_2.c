/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchez <abouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:15:12 by abouchez          #+#    #+#             */
/*   Updated: 2022/07/24 18:48:23 by abouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string_utils.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (whitespace(str[i]) == 1)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (sign * nb);
}

char	*ft_strtrim(char *str)
{
	int		i;
	int		j;
	int		i1;
	char	*tab;

	i = 0;
	j = 0;
	while (whitespace(str[i]) == 1)
		i++;
	i1 = i;
	while (str[i])
		i++;
	while (whitespace(str[i - 1]) == 1)
		i--;
	tab = malloc((i - i1 + 1) * sizeof(char));
	if (!tab)
		return (0);
	while (i1 != i)
	{
		tab[j++] = str[i1];
		i1++;
	}
	tab[j++] = '\0';
	return (tab);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_println(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
