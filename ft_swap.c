/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:51:01 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/31 17:00:06 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapx(t_list **stack, t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		ft_ferror(a, b);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_swap(char *s, t_list **a, t_list **b)
{
	if (a == NULL || b == NULL)
		ft_ferror(a, b);
	if (s[0] == 's' && s[1] == 'a')
		ft_swapx(a, a, b);
	else if (s[0] == 's' && s[1] == 'b')
		ft_swapx(b, a, b);
	else if (s[0] == 's' && s[1] == 's')
	{
		ft_swapx(a, a, b);
		ft_swapx(b, a, b);
	}
	else
		ft_ferror(a, b);
	ft_printf("%s\n", s);
}
