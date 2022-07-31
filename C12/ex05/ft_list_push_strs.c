/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:22:17 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 10:37:00 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*elem;
	t_list	*prev_elem;
	int		i;

	elem = 0;
	prev_elem = 0;
	i = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem->next = prev_elem;
		prev_elem = elem;
		i++;
	}
	return (elem);
}
