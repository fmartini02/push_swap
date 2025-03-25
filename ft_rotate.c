/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:49:30 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/25 12:08:49 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rrx(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	first = *stack;
	last = ft_lstlast(*stack);
	while (tmp->next != last)
		tmp = tmp->next;
	second_last = tmp;
	last->next = first;
	*stack = last;
	second_last->next = NULL;
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rx(a);
	ft_rx(b);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rrx(a);
	ft_rrx(b);
}

void	ft_rotate(char *str, t_list **a, t_list **b)
{
	if (ft_strcmp(str, "ra") == 0)
		ft_rx(a);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rx(b);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rrx(a);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrx(b);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rr(a, b);
	else
		ft_ferror(a, b);
	if ((*a)->flag == 0)
		ft_printf("%s\n", str);
}
