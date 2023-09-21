/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:06:09 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/20 18:18:24 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void    ft_check_digit(char **av);
void    ft_check_dubles(t_list **stack ,int ac);
void    ft_check_rules(char **av);
void    ft_splitfication(char *s, t_list **stack_a, int ac);
void    ft_error(void);
void    ft_ferror(void);
void    ft_print_list(t_list *stack_a);
void    ft_lstremove_front(t_list **lst);
void    ft_rotate(char *str, t_list **stack_a, t_list **stack_b);
void    ft_swapx(t_list **stack);
void    ft_push(char *str, t_list **stack_reciver, t_list **stack_giver);
void    ft_sorting(t_list **stack_a, t_list **stack_b);
void    ft_sort_three(t_list **stack_a, t_list **stack_b);
void    ft_sort_two(t_list **stack_a, t_list **stack_b);
void    ft_swap(char *s, t_list **stack_a, t_list **stack_b);
void    ft_get_position(t_list **stack);
void    ft_sorting(t_list **stack_a, t_list **stack_b);
void    ft_sort_a(t_list **a, t_list **b);
void    ft_sort_b(t_list **a, t_list **b);
void    ft_sec_magg(t_list **a, t_list **b);
void    ft_reconstruct(t_list **a, t_list **b);
int     ft_check_order(t_list **stack_a);
int     ft_optimizer(t_list **a, t_list **b);
void    ft_ult_magg(t_list **a, t_list **b);
void    ft_pri_min_b(t_list **a, t_list **b);
int     ft_first_pos(t_list **a, t_list **b);
int     ft_greater(t_list **b);
int     ft_smaller(t_list **b);
int     ft_utils(t_list **b);
void    ft_sorty(t_list **a, t_list **b);
int     ft_check_order_b(t_list **a, t_list **b);
void    ft_sorty_utils (t_list **b, t_list **a);

#endif