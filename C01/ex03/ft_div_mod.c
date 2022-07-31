/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:19:55 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/09 15:14:24 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	quotient;
	int	remainder;

	if (b == 0)
		return ;
	quotient = a / b;
	remainder = a % b;
	*div = quotient;
	*mod = remainder;
}
