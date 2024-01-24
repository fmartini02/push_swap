/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:42:27 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/13 17:14:22 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_greater_dist(t_list **b, int mag)
{
	t_list	*tmp;
	int		d;

	tmp = *b;
	d = 0;
	if (ft_find_half(tmp, ft_dist_from_top(b, mag)) == 1)
	{
		while (tmp->pos != mag)
		{
			tmp = tmp->next;
			d++;
		}
	}
	else if (ft_find_half(tmp, ft_dist_from_top(b, mag)) == 2)
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
	if (ft_find_half(tmp, ft_dist_from_top(b, min)) == 1)
	{
		while (tmp->pos != min)
		{
			tmp = tmp->next;
			d++;
		}
	}
	else if (ft_find_half(tmp, ft_dist_from_top(b, min)) == 2)
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

int	ft_find_half(t_list *b, int i)
{
	int	j;

	j = i;
	if (j < ft_lstsize(b) / 2)
		return (1);
	else if (j >= ft_lstsize(b) / 2)
		return (2);
}
