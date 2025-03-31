/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:42:36 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/21 15:43:12 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b(t_list **a, t_list **b)
{
	int	n_c;
	int	rra_count;

	n_c = ft_set_chunk_number(ft_lstsize(*b)) - 1;
	rra_count = 0;
	while (n_c >= 0)
	{
		rra_count = ft_push2a_logic(a, b, n_c);
		while (rra_count-- > 0)
			ft_rotate("rra", a, b);
		rra_count = 0;
		if (!ft_chunk_status(b, n_c))
			n_c--;
	}
}

void	ft_sorting(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		n_c;
	int		size;

	tmp = *a;
	n_c = 0;
	size = ft_lstsize(*a);
	if (ft_check_order_a(a) == 1)
		return ;
	while (*a)
	{
		ft_sort_logic_a(a, b, n_c);
		if (!ft_find_chunk(a, n_c))
		{
			n_c += 2;
			if (n_c > (ft_set_chunk_number(size) - 1))
				ft_sort_b(a, b);
			if (ft_check_order_a(a) == 1)
				return ;
		}
	}
}
