/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:10:28 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/15 09:52:36 by yaassila         ###   ########.fr       */
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
	if (x_int * x_int == nb)
		return (x_int);
	else
		return (0);
}
