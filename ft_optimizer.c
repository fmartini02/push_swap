/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:50 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/13 17:10:10 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cmp_moves(t_list **b, int magg, int min)
{
	t_list	*tmp;
	int		r;
	int		dis_mag;
	int		dis_min;

	r = 0;
	tmp = *b;
	dis_mag = ft_greater_dist(b, magg);
	dis_min = ft_smaller_dist(b, min);
	if (dis_mag < dis_min)
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
