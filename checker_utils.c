/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:53 by francema          #+#    #+#             */
/*   Updated: 2025/04/03 14:07:56 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *op, t_list **a, t_list **b)
{
	if (!ft_strcmp(op, "sa"))
		ft_swap("sa", a, b);
	else if (!ft_strcmp(op, "sb"))
		ft_swap("sb", a, b);
	else if (!ft_strcmp(op, "ss"))
		ft_swap("ss", a, b);
}

void	push(char *op, t_list **a, t_list **b)
{
	if (!ft_strcmp(op, "pa"))
		ft_push("pa", a, b);
	else if (!ft_strcmp(op, "pb"))
		ft_push("pb", b, a);
}

void	rotate(char *op, t_list **a, t_list **b)
{
	if (!ft_strcmp(op, "ra"))
		ft_rotate("ra", a, b);
	else if (!ft_strcmp(op, "rb"))
		ft_rotate("rb", a, b);
	else if (!ft_strcmp(op, "rr"))
		ft_rotate("rr", a, b);
	else if (!ft_strcmp(op, "rra"))
		ft_rotate("rra", a, b);
	else if (!ft_strcmp(op, "rrb"))
		ft_rotate("rrb", a, b);
	else if (!ft_strcmp(op, "rrr"))
		ft_rotate("rrr", a, b);
}

int	check_op(char *s)
{
	static char	*ops[] = {"sa\n", "sb\n", "ss\n", "ra\n", "rb\n",
		"rr\n", "rra\n", "rrb\n", "rrr\n", "pb\n", "pa\n", "\n", NULL};
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (ops[i])
	{
		if (!ft_strcmp(s, ops[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*get_ops(t_list **a, t_list **b)
{
	char	*tmp;
	char	*op;

	tmp = get_next_line(0);
	if (check_op(tmp))
	{
		free(tmp);
		ft_error(a, b);
	}
	op = ft_strdup("");
	while (tmp)
	{
		op = ft_strjoin(op, tmp);
		free(tmp);
		tmp = get_next_line(0);
		if (check_op(tmp))
		{
			free(tmp);
			ft_error(a, b);
		}
	}
	return (op);
}
