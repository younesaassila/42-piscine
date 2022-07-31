/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchez <abouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:12:34 by abouchez          #+#    #+#             */
/*   Updated: 2022/07/24 16:24:57 by abouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	char	c1;
	char	c2;

	c1 = *s1;
	c2 = *s2;
	while (c1 == c2)
	{
		if (c1 == '\0')
			return (c1 - c2);
		c1 = *s1++;
		c2 = *s2++;
	}
	return (c1 - c2);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!copy)
		return (0);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_get_int_length(int nbr)
{
	if (nbr < 0)
		return (2 + ft_get_int_length(-(nbr / 10)));
	else if (nbr >= 10)
		return (1 + ft_get_int_length(nbr / 10));
	return (1);
}

int	whitespace(char str)
{
	if ((str <= 13 && str >= 9) || str == ' ')
		return (1);
	return (0);
}
