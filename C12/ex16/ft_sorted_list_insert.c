/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:19:57 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 14:42:22 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_insert_elem(t_list **begin_list, t_list *prev, t_list *list_ptr,
		t_list *elem)
{
	if (!prev)
		*begin_list = elem;
	else
		prev->next = elem;
	if (elem)
		elem->next = list_ptr;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*prev;
	t_list	*list_ptr;
	t_list	*elem;

	prev = 0;
	list_ptr = *begin_list;
	elem = ft_create_elem(data);
	if (!elem)
		return ;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, elem->data) > 0)
		{
			ft_insert_elem(begin_list, prev, list_ptr, elem);
			return ;
		}
		prev = list_ptr;
		list_ptr = list_ptr->next;
	}
	ft_insert_elem(begin_list, prev, list_ptr, elem);
}
