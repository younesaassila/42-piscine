/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:23:22 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/24 18:48:06 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/errors.h"
#include "../includes/solve.h"
#include "../includes/string_utils.h"
#include <stdlib.h>

int	is_input_valid(char *input)
{
	int	i;

	if (ft_strlen(input) < 1)
		return (0);
	i = 0;
	while (input[i] != '\0')
	{
		if (!('0' <= input[i] && input[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char	*remove_leading_zeros(char *input)
{
	if (ft_strcmp(input, "0") == 0)
		return (input);
	while (*input == '0')
		input++;
	if (*input == '\0')
		return (0);
	return (input);
}

char	*get_formatted_input(int argc, char *argv[])
{
	char	*fmt_input;

	if (argc == 2)
		fmt_input = argv[1];
	if (argc == 3)
		fmt_input = argv[2];
	if (!fmt_input || !is_input_valid(fmt_input))
		return (0);
	fmt_input = remove_leading_zeros(fmt_input);
	if (!fmt_input)
		return (0);
	return (fmt_input);
}

void	free_dicts(int argc, t_dict *dict, t_dict *user_dict)
{
	ft_free_dict(dict);
	if (argc == 3)
		ft_free_dict(user_dict);
}

int	main(int argc, char *argv[])
{
	t_dict	*dict;
	t_dict	*user_dict;
	char	*input;
	char	*result;

	if (argc == 2 || argc == 3)
		dict = ft_parse_dict_file("numbers.dict");
	if (argc == 3)
		user_dict = ft_parse_dict_file(argv[1]);
	input = get_formatted_input(argc, argv);
	if (!input)
		return (ft_error());
	if (!dict)
		return (ft_dict_error());
	if (!user_dict && argc == 3)
		return (ft_dict_error());
	else if (argc == 3)
		ft_dict_replace_values(dict, user_dict);
	result = ft_get_result(dict, input);
	if (!result)
		return (ft_dict_error());
	ft_println(result);
	free(result);
	free_dicts(argc, dict, user_dict);
	return (0);
}
