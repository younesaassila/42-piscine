/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:36:05 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/11 16:13:55 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alphanumeric(char c);
int		ft_is_alpha(char c);
int		ft_is_numeric(char c);

char	*ft_strcapitalize(char *str)
{
	int		uppercase;
	int		i;
	char	c;

	uppercase = 1;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (uppercase && ('a' <= c && c <= 'z'))
			str[i] = c - 32;
		if (!uppercase && ('A' <= c && c <= 'Z'))
			str[i] = c + 32;
		if (ft_is_alphanumeric(c))
			uppercase = 0;
		else
			uppercase = 1;
		i++;
	}
	return (str);
}

int	ft_is_alphanumeric(char c)
{
	return (ft_is_alpha(c) || ft_is_numeric(c));
}

int	ft_is_alpha(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
