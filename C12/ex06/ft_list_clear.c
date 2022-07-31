/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:38:31 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/27 11:27:02 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*elem;
	t_list	*next;

	elem = begin_list;
	while (elem)
	{
		next = elem->next;
		(*free_fct)(elem->data);
		free(elem);
		elem = next;
	}
}
