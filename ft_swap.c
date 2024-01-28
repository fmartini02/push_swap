/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:51:01 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:38:59 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapx(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		ft_ferror();
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_swap(char *s, t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		ft_ferror();
	if (s[0] == 's' && s[1] == 'a')
		ft_swapx(stack_a);
	else if (s[0] == 's' && s[1] == 'b')
		ft_swapx(stack_b);
	else if (s[0] == 's' && s[1] == 's')
	{
		ft_swapx(stack_a);
		ft_swapx(stack_b);
	}
	else
		ft_ferror();
	ft_printf("%s\n", s);
}
