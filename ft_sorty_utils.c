/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorty_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:11:17 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/20 18:26:17 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_case_1(t_list **a, t_list **b)
{
    if ((*b)->pos < (*b)->next->pos && (*b)->pos < (*b)->next->next->pos) //pri min
    {
        if((*b)->next->pos > (*b)->next->next->pos)
            ft_rotate("rb", a, b);
        else
        {
            ft_rotate("rb", a, b);
            ft_rotate("rb", a, b);
        }
        ft_push("pa", a, b);
        return (1);
    }
    else
        return (0);
}
int ft_case_2(t_list **a, t_list **b)
{
    if ((*b)->pos > (*b)->next->pos && (*b)->pos < (*b)->next->next->pos)
        ft_rotate("rrb", a, b);
    else if ((*b)->pos < (*b)->next->pos && (*b)->pos > (*b)->next->next->pos)
        ft_swap("sb", a, b);
    else
        return (0);
    ft_push("pa", a, b);
    return (1);
}

int ft_case_3(t_list **a, t_list **b)
{
    if(ft_lstsize(*b) == 2)
    {
        if((*b)->pos < (*b)->next->pos)
            ft_swap("rb", a, b);
        ft_push("pa", a, b);
        return (1);
    }
    else if (ft_lstsize(*b) == 1)
        ft_push("pa", a, b);
    else
        return (0);
}

void    ft_sorty_utils (t_list **b, t_list **a)
{
    if(ft_case_1(a, b) == 1) //pri min
        return ;
    else if(ft_case_2(a, b) == 1) //sec magg || ult magg
        return ;
    else if(ft_case_3(a, b) == 1) //2 || 1 elm.
        return ;
    else
        ft_push("pa", a, b);
}