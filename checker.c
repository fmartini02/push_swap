/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:52:43 by francema          #+#    #+#             */
/*   Updated: 2025/03/25 18:18:49 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_op(char *op, t_list **a, t_list **b)
{
	char	**op_s;
	int		i;

	op_s = ft_split(op, '\n');
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
		check_limits(av, 1, a, b);
		ft_build_stack(a, av, ac, 1);
		ft_check_dubles(a, b, ac, NULL);
	}
	else if (ac == 2)
		ft_splitfication(av[1], a, b, ac, 1);
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
	char	*tmp;

	b = NULL;
	a = NULL;
	main_utils(&a, &b, ac, av);
	tmp = get_next_line(0);
	op = "";
	while (tmp)
	{
		op = ft_strjoin(op, tmp);
	//	printf("op: %s\n", op);
		free(tmp);
		tmp = get_next_line(0);
	}
	ft_do_op(op, &a, &b);
	free(op);
	if (ft_check_order_a(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&a, &b);
	return (0);
}
