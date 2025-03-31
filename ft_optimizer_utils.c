/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:42:27 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/21 15:54:58 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_which_half(t_list *b, int i)
{
	int	j;
	int	r;

	j = i;
	r = 0;
	if (j < ft_lstsize(b) / 2)
		r = 1;
	else if (j >= ft_lstsize(b) / 2)
		r = 2;
	return (r);
}

int	ft_greater_dist(t_list **b, int mag)
{
	t_list	*tmp;
	int		d;

	tmp = *b;
	d = 0;
	if (ft_which_half(tmp, ft_dist_from_top(b, mag)) == 1)
	{
		while (tmp->pos != mag)
		{
			tmp = tmp->next;
			d++;
		}
	}
	else if (ft_which_half(tmp, ft_dist_from_top(b, mag)) == 2)
	{
		while (tmp->pos != mag)
		{
			tmp = tmp->next;
			d++;
		}
		d = ft_lstsize(*b) - d;
	}
	return (d + 1);
}

int	ft_smaller_dist(t_list **b, int min)
{
	t_list	*tmp;
	int		d;

	tmp = *b;
	d = 0;
	if (ft_which_half(tmp, ft_dist_from_top(b, min)) == 1)
	{
		while (tmp->pos != min)
		{
			tmp = tmp->next;
			d++;
		}
	}
	else if (ft_which_half(tmp, ft_dist_from_top(b, min)) == 2)
	{
		while (tmp->pos != min)
		{
			tmp = tmp->next;
			d++;
		}
		d = ft_lstsize(*b) - d;
	}
	return (d + 3);
}

int	ft_chunk_status(t_list **b, int n_c)
{
	t_list	*tmp;
	int		r;

	r = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->chunk == n_c)
			r = 1;
		tmp = tmp->next;
	}
	return (r);
}
