/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:36:10 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/18 16:30:06 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_find_index(charset, str[i]) == -1)
		i++;
	return (i);
}

char	*ft_strdup(char *src, char *charset)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(src, charset);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (dest);
	i = 0;
	while (src[i] != '\0' && ft_find_index(charset, src[i]) == -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_get_char_ptr_arr_len(char *str, char *charset)
{
	int		i;
	int		size;
	int		within_elem;
	char	c;

	size = 0;
	i = 0;
	within_elem = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (ft_find_index(charset, c) != -1)
			within_elem = 0;
		else if (!within_elem)
		{
			within_elem = 1;
			size++;
		}
		i++;
	}
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	int		char_ptr_arr_len;
	char	**char_ptr_arr;
	int		within_elem;
	int		i;
	int		j;

	char_ptr_arr_len = ft_get_char_ptr_arr_len(str, charset);
	char_ptr_arr = (char **)malloc((char_ptr_arr_len + 1) * sizeof(char *));
	if (char_ptr_arr == NULL)
		return (char_ptr_arr);
	i = -1;
	j = 0;
	within_elem = 0;
	while (str[++i] != '\0')
	{
		if (ft_find_index(charset, str[i]) != -1)
			within_elem = 0;
		else if (!within_elem)
		{
			within_elem = 1;
			char_ptr_arr[j++] = ft_strdup(str + i, charset);
		}
	}
	char_ptr_arr[j] = 0;
	return (char_ptr_arr);
}
