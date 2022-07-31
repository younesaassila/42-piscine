/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:25:46 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/09 15:14:12 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	quotient;
	int	remainder;

	if (*b == 0)
		return ;
	quotient = *a / *b;
	remainder = *a % *b;
	*a = quotient;
	*b = remainder;
}
