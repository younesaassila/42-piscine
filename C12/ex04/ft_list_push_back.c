/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:06:55 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 14:54:48 by yaassila         ###   ########.fr       */
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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*last_elem;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	last_elem = ft_list_last(*begin_list);
	if (last_elem)
		last_elem->next = new_elem;
	else
		*begin_list = new_elem;
}
