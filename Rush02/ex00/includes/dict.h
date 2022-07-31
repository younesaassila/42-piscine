/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:49:13 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:47:45 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct s_t_dict
{
	char	*key;
	char	*value;
}			t_dict;

t_dict		*ft_parse_dict_file(const char *path);
char		*ft_parse_dict_key(char *line);
char		*ft_parse_dict_value(char *line);
int			ft_dict_size(t_dict *dict);
char		*ft_dict_get(t_dict *dict, char *key);
int			ft_dict_set(t_dict *dict, char *key, char *value);
void		ft_dict_replace_values(t_dict *dict1, t_dict *dict2);
int			ft_dict_key_maxlen(t_dict *dict);
void		ft_free_dict(t_dict *dict);

#endif
