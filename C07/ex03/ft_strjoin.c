/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:04 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/19 13:32:30 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_final_length(int size, char **strs, int sep_len)
{
	int	final_len;
	int	i;

	final_len = 0;
	i = 0;
	while (i < size)
	{
		final_len += ft_strlen(strs[i]);
		final_len += sep_len;
		i++;
	}
	final_len -= sep_len;
	return (final_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*res;
	char	*ptr;
	int		i;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	len = get_final_length(size, strs, ft_strlen(sep));
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	ptr = res;
	i = -1;
	while (++i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(ptr, sep);
			ptr += ft_strlen(sep);
		}
	}
	*ptr = '\0';
	return (res);
}
