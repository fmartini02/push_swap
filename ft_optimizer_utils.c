/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:36:11 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/03 16:12:01 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// int ft_fin_s_d(t_list **b, int n_c)
// {
//     t_list  *tmp;
//     int     s;
//     int     d;
//     int     i;

//     tmp = *b;
//     d = 1;
//     i = 0;
//     s = tmp->pos;
//     if(ft_lstsize (tmp) == 2)
//         return (2);
//     while(tmp->chunk == n_c)
//     {
//         if(s < tmp->next->pos)
//             tmp = tmp->next;
//         else if(s > tmp->next->pos)
//         {
//             s = tmp->next->pos;
//             tmp = tmp->next;
//             d = i;
//         }
//         i++;
//     }
//     return (d);
// }

// int   ft_first_pos(t_list **a, t_list **b)
// {
//     if(ft_greater(b) == 0)
//     {
//        if((*b)->pos > (*b)->next->pos)
//         return (0);
//        else if((*b)->pos < (*b)->next->pos)
//         {
//             ft_swap("sb", a, b);
//             return (0);
//         }
//     }
//     else if(ft_greater(b) == 1)
//         return (1);
//     else if(ft_greater(b) == 2)
//         return (2);
// }
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