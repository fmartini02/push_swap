/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:49:30 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:41:44 by fmartini         ###   ########.fr       */
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

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
}

void	ft_rotate(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "ra") == 0)
		ft_rx(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rx(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rrx(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrx(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rr(stack_a, stack_b);
	else
		ft_ferror();
	ft_printf("%s\n", str);
}
