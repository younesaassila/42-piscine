/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:56:00 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 14:17:27 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	ft_swap(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	size;
	int	i;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		ft_swap(ft_list_at(begin_list, i), ft_list_at(begin_list, size - i
				- 1));
		i++;
	}
}
