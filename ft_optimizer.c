/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:50 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/19 17:24:52 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_optimizer(t_list **a, t_list **b)
{
    int i;
    int dif;
    t_list *tmp;

    dif = 0;
    tmp = *b;
    i = tmp->pos;
    while(tmp->next)
    {
        if(ft_first_pos(a, b) == 0)
            return(dif);
        else if(ft_first_pos(a, b) == 2)
            return (dif);
        else if((*a)->pos - i !=1)
        {
            dif++;
            tmp = tmp->next;
            i = tmp->pos;
        }
        else
        {
            if(dif >= ft_lstsize(*b) / 2)
                dif = dif - ft_lstsize(*b);
            else if (dif <= ft_lstsize(*b) / 2)
                dif = dif;
            return (dif);
        }
    }
    return (dif);
}
