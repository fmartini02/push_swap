/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:06:44 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/08 17:06:02 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sorting(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = ft_lstsize(*stack_a);
    ft_get_position(stack_a);
    if (size == 2)
        ft_sort_two(stack_a, stack_b);
    else if (size == 3)
        ft_sort_three(stack_a, stack_b);
    //else if (size == 4)
        //ft_sort(stack_a, stack_b);
}
void    ft_sort_two(t_list **stack_a, t_list **stack_b)
{
    if ((*stack_a)->content > (*stack_a)->next->content)
        ft_rotate("ra", stack_a, stack_b);
}
void    ft_sort_three(t_list **stack_a, t_list **stack_b)
{
    ft_sort_two(stack_a, stack_b);
    ft_push("pb", stack_a, stack_b);
    ft_sort_two(stack_a, stack_b);
    ft_push("pa", stack_a, stack_b);
    ft_sort_two(stack_a, stack_b);
}
// int c =1;

// while(c)
// {
//     i = 0;
//     if(check_order(stack_a, stack_b)!= 1)
//         ft_sort(stack_a,stack_b);
//         i=1;
//     else
//         printf("si cazzo");
// }