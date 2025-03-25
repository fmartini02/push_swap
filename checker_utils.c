/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:53 by francema          #+#    #+#             */
/*   Updated: 2025/03/25 14:12:30 by francema         ###   ########.fr       */
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
