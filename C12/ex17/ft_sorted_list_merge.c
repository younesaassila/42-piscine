/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:43:30 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 15:03:52 by yaassila         ###   ########.fr       */
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

void	ft_sorted_list_insert(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*prev;
	t_list	*list_ptr;

	prev = 0;
	list_ptr = *begin_list;
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*elem;
	t_list	*next;

	elem = begin_list2;
	while (elem)
	{
		next = elem->next;
		ft_sorted_list_insert(begin_list1, elem, cmp);
		elem = next;
	}
}
