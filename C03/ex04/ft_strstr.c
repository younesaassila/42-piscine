/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:37:24 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/12 14:22:29 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

char	*ft_strstr(char *str, char *to_find)
{
	int	to_find_len;
	int	i;
	int	j;

	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != to_find[j])
			j = 0;
		if (str[i] == to_find[j])
			j++;
		if (j == to_find_len)
			return (str + i - (j - 1));
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
