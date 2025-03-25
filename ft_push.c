/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:51:18 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/25 14:13:14 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_px(t_list **stack_reciver, t_list **stack_giver)
{
	t_list	*tmp;

	if (*stack_giver == NULL)
		ft_ferror(stack_giver, stack_reciver);
	tmp = (*stack_giver)->next;
	(*stack_giver)->next = *stack_reciver;
	*stack_reciver = *stack_giver;
	*stack_giver = tmp;
}

void	ft_push(char *str, t_list **stack_reciver, t_list **stack_giver)
{
	if (stack_giver == NULL)
		ft_ferror(stack_giver, stack_reciver);
	if (str[1] == 'a')
		ft_px(stack_reciver, stack_giver);
	else if (str[1] == 'b')
		ft_px(stack_reciver, stack_giver);
	else
		ft_ferror(stack_giver, stack_reciver);
	if ((*stack_reciver)->flag == 0)
		ft_printf("%s\n", str);
}
