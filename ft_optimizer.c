/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:50 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/21 15:52:02 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cmp_moves(t_list **b, int magg, int min)
{
	t_list	*tmp;
	int		r;
	int		dist_num_mag;
	int		dist_num_min;

	r = 0;
	tmp = *b;
	dist_num_mag = ft_greater_dist(b, magg);
	dist_num_min = ft_smaller_dist(b, min);
	if (dist_num_mag < dist_num_min)
		r = 1;
	return (r);
}

int	ft_dist_from_top(t_list **b, int num)
{
	t_list	*tmp;
	int		i;

	tmp = *b;
	i = 0;
	while (tmp->pos != num)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_find_greater_in_chunk(t_list **b, int n_c)
{
	t_list	*tmp;
	int		r;

	tmp = *b;
	while (tmp->chunk != n_c && tmp)
		tmp = tmp->next;
	if (tmp->chunk == n_c)
		r = tmp->pos;
	while (tmp)
	{
		if (tmp->chunk == n_c && r < tmp->pos)
			r = tmp->pos;
		tmp = tmp->next;
	}
	return (r);
}

int	ft_find_smaller_in_chunk(t_list **b, int n_c)
{
	t_list	*tmp;
	int		r;

	tmp = *b;
	while (tmp->chunk != n_c && tmp)
		tmp = tmp->next;
	if (tmp->chunk == n_c)
		r = tmp->pos;
	while (tmp)
	{
		if (r > tmp->pos && tmp->chunk == n_c)
			r = tmp->pos;
		tmp = tmp->next;
	}
	return (r);
}
