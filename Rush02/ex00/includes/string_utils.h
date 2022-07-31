/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:08:36 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 16:24:24 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strtrim(char *str);
int		ft_atoi(char *str);
int		ft_get_int_length(int nbr);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		whitespace(char str);
void	ft_println(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
