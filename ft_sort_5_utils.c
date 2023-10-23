/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:38:34 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:05:43 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5_utils(t_list **a, t_list **b)
{
	int	s;

	s = ft_lstsize(*a);
	if (s == 3)
		ft_sort_3(a, b);
	else if (s == 2)
	{
		if ((*a)->pos > (*a)->next->pos)
			ft_swap("sa", a, b);
	}
	s = ft_lstsize(*b);
	if (s == 2)
	{
		if ((*b)->pos < (*b)->next->pos)
			ft_swap("sb", a, b);
		ft_push("pa", a, b);
		ft_push("pa", a, b);
	}
	else if (s == 1)
		ft_push("pa", a, b);
}

void	ft_sort_3(t_list **a, t_list **b)
{
	if ((*a)->pos > (*a)->next->pos)
		ft_swap("sa", a, b);
	ft_push("pb", b, a);
	if ((*a)->pos > (*a)->next->pos)
		ft_swap("sa", a, b);
	ft_push("pa", a, b);
	if ((*a)->pos > (*a)->next->pos)
		ft_swap("sa", a, b);
}
