/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:51:44 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 13:47:52 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*elem;
	unsigned int	i;

	elem = begin_list;
	i = 0;
	while (i < nbr && elem)
	{
		elem = elem->next;
		i++;
	}
	return (elem);
}

int	ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*elem;

	size = 0;
	elem = begin_list;
	while (elem)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}

void	ft_swap(t_list *prev, t_list *list_ptr, t_list *other_list_ptr,
		t_list *next)
{
	if (prev)
		prev->next = other_list_ptr;
	other_list_ptr->next = list_ptr;
	list_ptr->next = next;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		swapped;
	t_list	*list_ptr;
	t_list	*other_list_ptr;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = -1;
		while (++i < ft_list_size(*begin_list) - 1)
		{
			list_ptr = ft_list_at(*begin_list, i);
			other_list_ptr = ft_list_at(*begin_list, i + 1);
			if ((*cmp)(list_ptr->data, other_list_ptr->data) > 0)
			{
				ft_swap(ft_list_at(*begin_list, i - 1), list_ptr,
					other_list_ptr, ft_list_at(*begin_list, i + 2));
				if (!ft_list_at(*begin_list, i - 1))
					*begin_list = other_list_ptr;
				swapped = 1;
			}
		}
	}
}
