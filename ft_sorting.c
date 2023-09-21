/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:06:44 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/20 18:59:43 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_sort_a(t_list **a, t_list **b)
{
    t_list  *pri;
    t_list  *sec;
    t_list  *ult;
    int     t;

    pri = *a;
    sec = pri->next;
    ult = ft_lstlast(*a);
    t = 0;
    while (ft_check_order(a)!= 1)
    {
        if(ult->pos == ft_lstsize(*a))
        {
            if(ult->pos - pri->pos ==1 && t++)
                ft_rotate("ra", a, b);
        }
        if(pri->pos > sec->pos && pri->pos > ult->pos) //pri magg.
            ft_rotate("ra", a, b);
        else if(sec->pos > pri->pos && sec->pos > ult->pos) //sec magg.
            ft_sec_magg(a, b);
        else if(ult->pos > pri->pos && ult->pos > sec->pos) //ult magg.
            ft_ult_magg(a, b);
        ft_sort_a(a, b);
    }
    while(t-- > 0)
        ft_rotate("rra", a, b);
}
void    ft_sort_b(t_list **a, t_list **b)
{
    t_list  *pri;
    t_list  *sec;
    t_list  *ult;

    if(*b == NULL || (*b)->next == NULL)
        return ;
    if((*b)->next->next == NULL)
    {
        if((*b)->pos < (*b)->next->pos)
            ft_swap("sb", a, b);
        return ;
    }
    pri = *b;
    sec = pri->next;
    ult = ft_lstlast(*b);
    if(pri->pos > sec->pos && pri->pos < ult->pos) //ult magg
       ft_rotate("rrb", a, b);
    else if (pri->pos < sec->pos && pri->pos > ult->pos) // sec magg
        ft_swap("sb", a, b);
    else if(pri->pos < sec->pos && pri->pos < ult->pos) // pri min
        ft_pri_min_b(a, b);
    else
    {
        if(ft_check_order(a) == 1)
            ft_reconstruct(a, b);
    } 
}

void    ft_reconstruct(t_list **a, t_list **b)
{
    int t;

    if(ft_lstsize(*b) <= 3)
    {
        ft_sorty(b, a);
        return ;
    }
    t = ft_optimizer(a, b);
    if( t > 0)
    {
        while(t > 0)
        {
            ft_rotate("rb", a, b);
            t--;
        }
    }
    else if (t < 0)
    {
        while(t < 0)
        {
            ft_rotate("rrb", a, b);
            t++;
        }
    }
    ft_push("pa", a, b);
}


void    ft_sorting(t_list **a, t_list **b)
{
    int s;

    s = 0;
    ft_get_position(a);
    ft_sort_a(a,b);
    while(ft_check_order_b(a, b) != 1 )
        ft_reconstruct(a, b);
    s = ft_lstsize(*b);
    while(s-- > 0)
        ft_push("pa", a, b);
}