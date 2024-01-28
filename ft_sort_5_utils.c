/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:38:34 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/25 15:52:04 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorty(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	ft_sort_3(a, b);
	if (tmp->pos < tmp->next->pos)
		ft_swap("sb", a, b);
	ft_push("pa", a, b);
	ft_push("pa", a, b);
}

void	ft_rsort_2(t_list **stack, t_list **a, t_list **b)
{
	if ((*stack)->pos < (*stack)->next->pos)
		ft_swap("sb", a, b);
}

void	ft_sort_2(t_list **stack, t_list **a, t_list **b)
{
	if ((*stack)->pos > (*stack)->next->pos)
		ft_swap("sa", a, b);
}

void	ft_sort_4(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		buff;

	tmp = *a;
	buff = 0;
	while (tmp)
	{
		if (tmp->pos == 1 || tmp->pos == 2)
		{
			ft_push("pb", b, a);
			buff++;
		}
		else
			ft_rotate("ra", a, b);
		if (buff == 2)
		{
			ft_rsort_2(b, a, b);
			ft_sort_2(a, a, b);
			ft_push("pa", a, b);
			ft_push("pa", a, b);
			return ;
		}
		tmp = *a;
	}
}

void	ft_sort_3(t_list **a, t_list **b)
{
	if ((*a)->pos < (*a)->next->pos && (*a)->next->pos < (*a)->next->next->pos)
		return ;
	else if ((*a)->pos > (*a)->next->pos
		&& (*a)->next->pos > (*a)->next->next->pos)
	{
		ft_rotate("ra", a, b);
		ft_swap("sa", a, b);
	}
	else if ((*a)->pos < (*a)->next->pos && (*a)->pos < (*a)->next->next->pos
		&& (*a)->next->pos > (*a)->next->next->pos)
	{
		ft_swap("sa", a, b);
		ft_rotate("ra", a, b);
	}
	else if ((*a)->pos > (*a)->next->pos && (*a)->pos > (*a)->next->next->pos
		&& (*a)->next->pos < (*a)->next->next->pos)
		ft_rotate("ra", a, b);
	else if ((*a)->pos > (*a)->next->pos && (*a)->pos < (*a)->next->next->pos)
		ft_swap("sa", a, b);
	else if ((*a)->next->pos > (*a)->pos
		&& (*a)->next->pos > (*a)->next->next->pos)
		ft_rotate("rra", a, b);
	else if ((*a)->next->next->pos > (*a)->pos
		&& (*a)->next->next->pos > (*a)->next->pos)
		ft_swap("sa", a, b);
}
