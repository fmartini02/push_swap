/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:51:18 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/13 17:07:17 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_px(t_list **stack_reciver, t_list **stack_giver)
{
	t_list	*tmp;

	if (*stack_giver == NULL)
		ft_ferror();
	tmp = (*stack_giver)->next;
	(*stack_giver)->next = *stack_reciver;
	*stack_reciver = *stack_giver;
	*stack_giver = tmp;
}

void	ft_push(char *str, t_list **stack_reciver, t_list **stack_giver)
{
	if (str[1] == 'a')
		ft_px(stack_reciver, stack_giver);
	else if (str[1] == 'b')
		ft_px(stack_reciver, stack_giver);
	else
		ft_ferror();
	ft_printf("%s\n", str);
}
