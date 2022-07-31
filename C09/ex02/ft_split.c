/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:43:10 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/21 14:07:49 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_char_separator(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !is_char_separator(charset, str[i]))
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
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != '\0' && !is_char_separator(charset, src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_tab_len(char *str, char *charset)
{
	int	len;
	int	within_word;
	int	i;

	len = 0;
	within_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_char_separator(charset, str[i]))
			within_word = 0;
		else if (!within_word)
		{
			within_word = 1;
			len++;
		}
		i++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	int		tab_len;
	char	**tab;
	int		within_word;
	int		i;
	int		j;

	tab_len = get_tab_len(str, charset);
	tab = (char **)malloc((tab_len + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = -1;
	j = 0;
	within_word = 0;
	while (str[++i] != '\0')
	{
		if (is_char_separator(charset, str[i]))
			within_word = 0;
		else if (!within_word)
		{
			within_word = 1;
			tab[j++] = ft_strdup(str + i, charset);
		}
	}
	tab[j] = 0;
	return (tab);
}
