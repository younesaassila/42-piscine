/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:02:27 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 16:03:57 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string_utils.h"

int	ft_dict_error(void)
{
	ft_putstr("Dict Error\n");
	return (1);
}

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (1);
}
