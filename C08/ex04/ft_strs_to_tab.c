/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:36:34 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/22 11:05:17 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	set_stock_str(t_stock_str *stock_str, int size, char *str, char *copy)
{
	stock_str->size = size;
	stock_str->str = str;
	stock_str->copy = copy;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	t_stock_str	*stock_str;
	int			i;

	tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock_str = (t_stock_str *)malloc(sizeof(t_stock_str));
		if (!stock_str)
			return (NULL);
		set_stock_str(stock_str, ft_strlen(av[i]), av[i], ft_strdup(av[i]));
		tab[i] = *stock_str;
		free(stock_str);
		i++;
	}
	stock_str = (t_stock_str *)malloc(sizeof(t_stock_str));
	if (!stock_str)
		return (NULL);
	set_stock_str(stock_str, 0, 0, 0);
	tab[i] = *stock_str;
	return (tab);
}
