/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:06:09 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:27:52 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void	ft_check_digit(char **av, int flag);
void	ft_check_dubles(t_list **stack, int ac);
int		ft_find_greater_in_chunk(t_list **stack, int n_c);
int		ft_find_smaller_in_chunk(t_list **stack, int n_c);
void	ft_splitfication(char *s, t_list **stack_a, int ac);
void	ft_set_position(t_list **stack);
void	ft_set_chunk_value(t_list **a, int c_size);
void	ft_chunking(t_list **a, t_list **b);
int		ft_set_chunk_number(int size);
int		ft_chunk_status(t_list **b, int n_c);
int		ft_find_chunk(t_list **a, int chunk);
void	ft_error(void);
void	ft_ferror(void);
void	ft_print_list(t_list *stack_a);
void	ft_lstremove_front(t_list **lst);
void	ft_rotate(char *str, t_list **stack_a, t_list **stack_b);
void	ft_swapx(t_list **stack);
void	ft_swap(char *s, t_list **stack_a, t_list **stack_b);
void	ft_push(char *str, t_list **stack_reciver, t_list **stack_giver);
int		ft_check_order_a(t_list **stack_a);
void	ft_sort_3(t_list **a, t_list **b);
void	ft_sort_5(t_list **a, t_list **b);
void	ft_sort_5_utils(t_list **a, t_list **b);
void	ft_sort_small(t_list **a, t_list **b);
void	ft_sorting(t_list **stack_a, t_list **stack_b);
void	ft_sort_logic_a(t_list **a, t_list **b, int n_c);
void	ft_sort_b(t_list **a, t_list **b);
void	ft_sort_logic_b(t_list **b, t_list **a, int num);
int		ft_buff_init(t_list **a, t_list **b, int n_c);
int		ft_cmp_moves(t_list **b, int magg, int min);
int		ft_greater_dist(t_list **b, int n_c);
int		ft_smaller_dist(t_list **b, int n_c);
int		ft_dist_from_top(t_list **b, int num);
int		ft_find_half(t_list *b, int i);
void	ft_free_stack(t_list **a, t_list **b);

#endif