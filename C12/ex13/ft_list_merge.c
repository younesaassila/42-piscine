/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:31:30 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 17:08:01 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*elem;
	t_list	*prev_elem;

	elem = begin_list;
	prev_elem = 0;
	while (elem)
	{
		prev_elem = elem;
		elem = elem->next;
	}
	return (prev_elem);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last_elem;

	last_elem = ft_list_last(*begin_list1);
	if (!last_elem)
		*begin_list1 = begin_list2;
	else
		last_elem->next = begin_list2;
}
