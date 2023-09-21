/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:48:27 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/20 18:39:05 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_get_position(t_list **stack)
{
    t_list  *current;
    t_list  *comp;

    current = *stack;
    while (current !=NULL)
    {
        comp = *stack;
        while(comp != NULL)
        {
            if(current->content > comp->content)
                current->pos++;
            comp = comp->next;
        }
        current->pos++;
        current = current->next;
    }
}

int ft_check_order_b(t_list **a, t_list **b)
{
    t_list  *tmp;

    tmp = *b;
    while(tmp->next != NULL)
    {
        if((tmp->pos - tmp->next->pos == 1) && tmp->next)
            tmp = tmp->next;
        else if((tmp->pos - tmp->next->pos !=1) && tmp->next)
            return (0);
    }
    return (1);
}
int ft_check_order(t_list **stack)
{
    t_list  *tmp;

    tmp = *stack;
    while(tmp->next != NULL)
    {
        if((tmp->next->pos - tmp->pos == 1) && tmp->next)
            tmp = tmp->next;
        else if ((tmp->next->pos - tmp->pos !=1) && tmp->next)
            return (0);
    }
    return (1);
}
void    ft_sorty (t_list **b, t_list **a)
{
    ft_sorty_utils(b, a);
}