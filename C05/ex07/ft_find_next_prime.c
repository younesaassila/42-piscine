/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:17:32 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/14 13:21:33 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	double	x;
	double	err;
	int		x_int;

	if (nb <= 0)
		return (0);
	x = 1;
	err = 1;
	while (!(-0.01 < err && err < 0.01))
	{
		err = (nb - x * x) / (2 * x);
		x += err;
	}
	x_int = x;
	return (x_int);
}

int	ft_is_prime(int nb)
{
	int	sqrt_nb;
	int	i;

	if (nb <= 1)
		return (0);
	sqrt_nb = ft_sqrt(nb);
	i = 2;
	while (i <= sqrt_nb)
	{
		if (!(i > 2 && i % 2 == 0))
		{
			if (nb % i == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (!ft_is_prime(i))
	{
		i++;
	}
	return (i);
}
