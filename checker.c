/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:52:43 by francema          #+#    #+#             */
/*   Updated: 2025/04/17 16:09:25 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_op_utils(t_list **a, t_list **b, char **op_s)
{
	int	i;

	i = 0;
	while (op_s[i])
	{
		if (*op_s[i] == 's')
			swap(op_s[i], a, b);
		else if (*op_s[i] == 'p')
			push(op_s[i], a, b);
		else if (*op_s[i] == 'r')
			rotate(op_s[i], a, b);
		if (check_error(a, b))
		{
			while (op_s[i])
			{
				free(op_s[i]);
				i++;
			}
			free(op_s);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_do_op(char *op, t_list **a, t_list **b)
{
	char	**op_s;
	int		i;

	op_s = ft_split(op, '\n');
	free(op);
	check_format(a, b, op_s);
	if (ft_do_op_utils(a, b, op_s))
	{
		ft_free_stack(a, b);
		exit(1);
	}
	i = 0;
	while (op_s[i])
	{
		free(op_s[i]);
		i++;
	}
	free(op_s);
}

void	main_utils(t_list **a, t_list **b, int ac, char **av)
{
	if (ac > 2)
	{
		if (ft_check_digit(av, 1))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		check_limits(av, 1);
		ft_build_stack(a, av, ac, 1);
		ft_check_dubles(a, b, NULL);
	}
	else if (ac == 2)
		ft_splitfication(av[1], a, b, 1);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	ft_set_position(a);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*op;

	b = NULL;
	a = NULL;
	main_utils(&a, &b, ac, av);
	op = get_ops(&a, &b);
	if (!op)
		return (1);
	ft_do_op(op, &a, &b);
	if (ft_check_order_a(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&a, &b);
	return (0);
}
