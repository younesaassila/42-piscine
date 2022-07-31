/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:10:00 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/25 19:52:23 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	direction;
	int	fn_result;
	int	i;

	direction = 0;
	i = 0;
	while (i < length - 1)
	{
		fn_result = (*f)(tab[i], tab[i + 1]);
		if (fn_result > 0 && direction < 0)
			return (0);
		if (fn_result < 0 && direction > 0)
			return (0);
		if (fn_result != 0)
			direction = fn_result;
		i++;
	}
	return (1);
}
