/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:10:15 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/24 17:39:31 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_sec_magg(t_list **a, t_list **b)
// {
//     if((*a)->pos > ft_lstlast(*a)->pos)
//     {
//         ft_rotate("rra", a, b);
//         ft_push("pb", b, a);
//         ft_sort_b(a, b);
//     }
//     else if((*a)->pos < ft_lstlast(*a)->pos)
//     {
//         ft_push("pb", b, a);
//         ft_rotate("ra", a, b);
//         ft_sort_b(a, b);
//     }
//     else
//     {
//         ft_swap("sa", a, b);
//         ft_rotate("ra", a, b);
//     }
// }
// void ft_ult_magg(t_list **a, t_list **b)
// {
//     t_list  *pri;
//     t_list  *sec;

//     pri = *a;
//     sec = pri->next;
//     if(pri->pos < sec->pos)
//         ft_push("pb", b, a);
//     else if (pri->pos > sec->pos)
//     {
//         ft_swap("sa", a, b);
//         ft_push("pb", b, a);
//     }
//     ft_sort_b(a, b);
// }

// void    ft_pri_min_b(t_list **a, t_list **b)
// {
//     t_list  *pri;
//     t_list  *sec;
//     t_list  *ult;

//     pri = *b;
//     sec = pri->next;
//     ult = ft_lstlast(*b);
//     if(sec->pos == ult->pos)
//         ft_swap("sb", a, b);
//     else if (pri->pos > ult->pos)
//     {
//         ft_swap("sb", a, b);
//         ft_rotate("rrb", a, b);
//     }
//     else if (pri->pos < ult->pos)
//         ft_rotate("rb", a, b);
// }

// int    ft_smaller(t_list **b)
// {
//     t_list  *pri;
//     int dif;

//     dif = 0;
//     pri = *b;
//     if(pri->pos < pri->next->pos)
//         return(0);
//     else if(pri->pos > pri->next->pos)
//         return(1);
// }*/