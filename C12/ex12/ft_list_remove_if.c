/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:11:52 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 12:30:20 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*list_ptr;
	t_list	*next;

	prev = 0;
	list_ptr = *begin_list;
	while (list_ptr)
	{
		next = list_ptr->next;
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			(*free_fct)(list_ptr->data);
			free(list_ptr);
		}
		else
			prev = list_ptr;
		list_ptr = next;
	}
}
