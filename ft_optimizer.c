/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:50 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/03 16:13:06 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int    ft_optimizer(t_list **a, t_list **b)
// {
//     int i;
//     int dif;
//     t_list *tmp;

//     dif = 0;
//     tmp = *b;
//     i = tmp->pos;
//     while(tmp->next)
//     {
//         if(ft_first_pos(a, b) == 0)
//             return(dif);
//         else if(ft_first_pos(a, b) == 2)
//             return (dif);
//         // else if((*a)->pos - i !=1)
//         // {
//         //     dif++;
//         //     tmp = tmp->next;
//         //     i = tmp->pos;
//         // }
//         else
//         {
//             if(dif >= ft_lstsize(*b) / 2)
//                 dif = dif - ft_lstsize(*b);
//             else if (dif <= ft_lstsize(*b) / 2)
//                 dif = dif;
//             return (dif);
//         }
//     }
//     return (dif);
// }

int ft_find_diff(t_list **a, t_list **b)
{
    int mag;
    int dif;
    t_list *tmp;
    int fine;

    fine = 0;
    tmp = *b;
    mag = ft_lstsize(*b);
    dif = 0;
    while(tmp->next && fine == 0)
    {
        if(tmp->pos < mag)
            dif++;
        else if(tmp->pos == mag)
        {
            if(dif >= ft_lstsize(*b) / 2)
                dif = dif - ft_lstsize(*b);
            else if (dif <= ft_lstsize(*b) / 2)
                dif = dif;
            fine = 1;
        }
        tmp = tmp->next;
    }
    return (dif);
}

int ft_optimizer(t_list **a, t_list **b)
{
    int     i;
    int     dif;
    t_list *tmp;
  
    i = (*b)->pos;
    tmp = *b;
    dif = ft_find_diff(a, b);
    return(dif);
}
int ft_cmp_moves(t_list **a, t_list **b, int chunk)
{
    t_list *tmp;
    int c;
    int d;
    int moves_mag;
    int moves_min;

    c = 2;
    d = 1;
    tmp = *b;
    while(tmp->chunk != chunk)
        tmp = tmp->next;
}