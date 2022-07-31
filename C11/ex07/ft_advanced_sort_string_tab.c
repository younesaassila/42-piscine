/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:51:51 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/25 12:57:34 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if ((*cmp)(*arr, *(arr + 1)) > 0)
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
