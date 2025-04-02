/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:52:43 by francema          #+#    #+#             */
/*   Updated: 2025/04/02 14:42:31 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_format_utils(t_list **a, t_list **b, char **op_s)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	ft_free_stack(a, b);
	i = 0;
	while (op_s[i])
	{
		free(op_s[i]);
		i++;
	}
	free(op_s);
	exit(1);
}

void	check_format(t_list **a, t_list **b, char **op_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (op_s[i])
	{
		while (ft_isalpha(op_s[i][j]))
			j++;
		if (op_s[i][j] && op_s[i][j] != '\n')
			check_format_utils(a, b, op_s);
		if (!op_s[i][j])
			return ;
		j = 0;
		i++;
	}
}

void	ft_do_op(char *op, t_list **a, t_list **b)
{
	char	**op_s;
	int		i;

	op_s = ft_split(op, '\n');
	free(op);
	check_format(a, b, op_s);
	i = 0;
	while (op_s[i])
	{
		if (*op_s[i] == 's')
			swap(op_s[i], a, b);
		else if (*op_s[i] == 'p')
			push(op_s[i], a, b);
		else if (*op_s[i] == 'r')
			rotate(op_s[i], a, b);
		i++;
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
