/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:36:11 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/19 17:03:19 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   ft_first_pos(t_list **a, t_list **b)
{
    if(ft_greater(b) == 0)
    {
       if((*b)->pos > (*b)->next->pos)
        return (0);
       else if((*b)->pos < (*b)->next->pos)
        {
            ft_swap("sb", a, b);
            return (0);
        }
    }
    else if(ft_greater(b) == 1)
        return (1);
    else if(ft_greater(b) == 2)
        return (2);
}
int ft_utils(t_list **b)
{
    int i;
    int dif;

    i = 0;
    dif = 0;
    if(i >= ft_lstsize(*b) / 2)
        dif = i - ft_lstsize(*b);
    else if (i <= ft_lstsize(*b) / 2)
        dif = i;
}



