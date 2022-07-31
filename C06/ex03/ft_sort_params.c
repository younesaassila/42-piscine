/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:29:53 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/14 15:01:20 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	c1 = str1[i];
	c2 = str2[i];
	return (c1 - c2);
}

char	**ft_sort_arr(char *arr[])
{
	int		i;
	int		swapped;
	char	*temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (arr[i] != 0 && arr[i + 1] != 0)
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
	return (arr);
}

int	main(int argc, char *argv[])
{
	char	**argv_sorted;
	int		i;

	if (argc > 1)
	{
		argv_sorted = ft_sort_arr(argv + 1);
		i = 0;
		while (i < argc - 1)
		{
			ft_putstr(argv_sorted[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
