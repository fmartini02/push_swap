/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_killer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:35:25 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:07:28 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp = tmp->next;
		free(*a);
		*a = tmp;
	}
	tmp = *b;
	while (tmp)
	{
		tmp = tmp->next;
		free(*b);
		*b = tmp;
	}
}
