/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaleem <asaleem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:05:05 by asaleem           #+#    #+#             */
/*   Updated: 2022/07/17 15:20:28 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int		*get_clues_from_input(char *str);
int		check_case(int tab[4][4], int pos, int entry[16]);
int		check_double(int tab[4][4], int pos, int num);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		solve(int tab[4][4], int clues[16], int pos);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_puterr(char *str);

#endif
