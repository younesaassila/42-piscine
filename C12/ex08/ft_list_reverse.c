/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:37:24 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 11:45:57 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*elem;
	t_list	*next;

	prev = 0;
	next = 0;
	elem = *begin_list;
	while (elem)
	{
		next = elem->next;
		elem->next = prev;
		prev = elem;
		elem = next;
	}
	*begin_list = prev;
}
