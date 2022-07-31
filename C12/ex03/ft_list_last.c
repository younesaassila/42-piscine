/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:58:15 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 10:05:15 by yaassila         ###   ########.fr       */
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
