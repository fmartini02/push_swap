/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:48:27 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:06:23 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position(t_list **stack)
{
	t_list	*current;
	t_list	*comp;

	current = *stack;
	current->pos = 0;
	while (current != NULL)
	{
		comp = *stack;
		while (comp != NULL)
		{
			if (current->content > comp->content)
				current->pos++;
			comp = comp->next;
		}
		current->pos++;
		current = current->next;
	}
}

int	ft_check_order_a(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if ((tmp->next->pos - tmp->pos == 1) && tmp->next)
			tmp = tmp->next;
		else if ((tmp->next->pos - tmp->pos != 1) && tmp->next)
			return (0);
	}
	return (1);
}

void	ft_sort_logic_a(t_list **a, t_list **b, int n_c)
{
	if ((*a)->chunk == (n_c + 1))
		ft_push("pb", b, a);
	else if ((*a)->chunk == n_c)
	{
		ft_push("pb", b, a);
		ft_rotate("rb", a, b);
	}
	else
		ft_rotate("ra", a, b);
}

void	ft_sort_logic_b(t_list **b, t_list **a, int num)
{
	t_list	*tmp;
	int		d;

	tmp = *b;
	d = ft_dist_from_top(b, num);
	if (ft_find_half(tmp, d) == 1)
	{
		while (d > 0)
		{
			ft_rotate("rb", a, b);
			d--;
		}
	}
	else if (ft_find_half(tmp, d) == 2)
	{
		d = ft_lstsize(*b) - d;
		while (d > 0)
		{
			ft_rotate("rrb", a, b);
			d--;
		}
	}
	ft_push("pa", a, b);
}

int	ft_buff_init(t_list **a, t_list **b, int n_c)
{
	int	buff_a;

	buff_a = 0;
	while (ft_chunk_status(b, n_c))
	{
		if (ft_cmp_moves(b, ft_find_greater_in_chunk(b, n_c),
				ft_find_smaller_in_chunk(b, n_c)))
			ft_sort_logic_b(b, a, ft_find_greater_in_chunk(b, n_c));
		else if (!ft_cmp_moves(b, ft_find_greater_in_chunk(b, n_c),
				ft_find_smaller_in_chunk(b, n_c)))
		{
			ft_sort_logic_b(b, a, ft_find_smaller_in_chunk(b, n_c));
			ft_rotate("ra", a, b);
			buff_a += 1;
		}
	}
	return (buff_a);
}
