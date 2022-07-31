/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:34:01 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/25 12:48:58 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		swapped;
	char	**arr;
	char	*temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		arr = tab;
		while (*arr && *(arr + 1))
		{
			if (ft_strcmp(*arr, *(arr + 1)) > 0)
			{
				temp = *arr;
				*arr = *(arr + 1);
				*(arr + 1) = temp;
				swapped = 1;
			}
			arr++;
		}
	}
}
