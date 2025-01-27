/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:06:09 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/27 19:24:08 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

int		ft_check_digit(char **av, int flag, t_list **a, t_list **b);
void	ft_check_dubles(t_list **a, t_list **b, int ac, char **t);
void	check_limits(char **av, int flag, t_list **a, t_list **b);
int		ft_find_greater_in_chunk(t_list **stack, int n_c);
int		ft_find_smaller_in_chunk(t_list **stack, int n_c);
void	ft_splitfication(char *s, t_list **stack_a, t_list **b, int ac);
void	ft_set_position(t_list **stack);
void	ft_set_chunk_value(t_list **a, int c_size);
void	ft_chunking(t_list **a, t_list **b);
int		ft_set_chunk_number(int size);
int		ft_chunk_status(t_list **b, int n_c);
int		ft_find_chunk(t_list **a, int chunk);
void	ft_error(t_list **stack_a, t_list **stack_b);
void	ft_ferror(t_list **stack_a, t_list **stack_b);
void	ft_print_list(t_list *stack_a);
void	ft_lstremove_front(t_list **lst);
void	ft_rotate(char *str, t_list **stack_a, t_list **stack_b);
void	ft_swapx(t_list **stack, t_list **a, t_list **b);
void	ft_swap(char *s, t_list **stack_a, t_list **stack_b);
void	ft_push(char *str, t_list **stack_reciver, t_list **stack_giver);
int		ft_check_order_a(t_list **stack_a);
void	ft_sort_3(t_list **a, t_list **b);
void	ft_sort_5(t_list **a, t_list **b);
void	ft_sort_small(t_list **a, t_list **b);
void	ft_sorting(t_list **stack_a, t_list **stack_b);
void	ft_sort_logic_a(t_list **a, t_list **b, int n_c);
void	ft_sort_b(t_list **a, t_list **b);
void	ft_sort_logic_b(t_list **b, t_list **a, int num);
int		ft_push2a_logic(t_list **a, t_list **b, int n_c);
int		ft_cmp_moves(t_list **b, int magg, int min);
int		ft_greater_dist(t_list **b, int n_c);
int		ft_smaller_dist(t_list **b, int n_c);
int		ft_dist_from_top(t_list **b, int num);
int		ft_which_half(t_list *b, int i);
void	ft_free_stack(t_list **a, t_list **b);
void	free_tmp(char **tmp);
void	ft_sorty(t_list **a, t_list **b);
void	ft_sort_4(t_list **a, t_list **b);

#endif
