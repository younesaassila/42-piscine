/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:18:42 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/10 10:06:34 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		ft_is_number(char *str);
int		ft_str_to_int(char *str);

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (argc == 1)
	{
		x = 5;
		y = 3;
	}
	if (argc >= 3)
	{
		if (!ft_is_number(argv[1]) || !ft_is_number(argv[2]))
		{
			return (write(1, "Number is invalid\n", 18));
		}
		x = ft_str_to_int(argv[1]);
		y = ft_str_to_int(argv[2]);
	}
	rush(x, y);
	return (0);
}

int	ft_is_number(char *str)
{
	int	is_number;
	int	i;

	is_number = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			is_number = 0;
		}
		i++;
	}
	return (is_number);
}

int	ft_str_to_int(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}
