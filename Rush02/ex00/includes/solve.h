/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:22:16 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:47:48 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "./dict.h"

char	*ft_get_result(t_dict *dict, char *input);
char	*ft_get_result_zero(t_dict *dict);
char	*ft_dgt_chars_to_str(char c1, char c2);
char	*ft_join_dgt_str(t_dict *dict, char *str, char *dgt_str,
			int is_hundreds);

#endif
