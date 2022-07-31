/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:22:08 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/23 17:21:55 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_UTILS_H
# define FILE_UTILS_H

int		ft_open_file(const char *path);
int		ft_close_file(int fd);
int		ft_lines_count(const char *path);
char	**ft_readlines(const char *path);

#endif
