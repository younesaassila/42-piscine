/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:45:58 by yaassila          #+#    #+#             */
/*   Updated: 2022/07/25 12:32:13 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operators.h"
#include "../includes/utils.h"

int	ft_show_error(char *msg)
{
	ft_putstr(msg);
	return (1);
}

int	ft_get_op_funcs_index(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '/')
		return (2);
	if (op == '*')
		return (3);
	if (op == '%')
		return (4);
	return (-1);
}

void	ft_calc(int (*op_funcs[5])(int, int), int value1, char op, int value2)
{
	int	result;
	int	op_funcs_index;

	result = 0;
	op_funcs_index = ft_get_op_funcs_index(op);
	if (0 <= op_funcs_index && op_funcs_index <= 4)
		result = (*op_funcs[op_funcs_index])(value1, value2);
	ft_putnbr(result);
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	int		value1;
	char	op;
	int		value2;
	int		(*op_funcs[5])(int, int);
	int		op_funcs_index;

	op_funcs[0] = &ft_add;
	op_funcs[1] = &ft_sub;
	op_funcs[2] = &ft_div;
	op_funcs[3] = &ft_mul;
	op_funcs[4] = &ft_mod;
	if (argc == 4)
	{
		value1 = ft_atoi(argv[1]);
		op = argv[2][0];
		value2 = ft_atoi(argv[3]);
		op_funcs_index = ft_get_op_funcs_index(op);
		if (op_funcs_index == 2 && value2 == 0)
			return (ft_show_error("Stop : division by zero\n"));
		else if (op_funcs_index == 4 && value2 == 0)
			return (ft_show_error("Stop : modulo by zero\n"));
		else
			ft_calc(op_funcs, value1, op, value2);
	}
	return (0);
}
