/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:17:49 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/18 16:55:16 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_chunk_number(int size)
{
	int	n_chunk;

	n_chunk = 0;
	if (size >= 500)
		n_chunk = 14;
	else if (size >= 100)
		n_chunk = 6;
	else
		n_chunk = 2;
	return (n_chunk);
}

int	ft_set_chunk_size(int size, int n_chunk)
{
	int	c_size;

	if (size % n_chunk == 0)
		c_size = size / n_chunk;
	else
		c_size = (size / n_chunk) + 1;
	return (c_size);
}

void	ft_set_chunk_value(t_list **a, int c_size)
{
	t_list	*tmp;

	tmp = *a;
	while (*a)
	{
		(*a)->chunk = (*a)->pos / c_size;
		*a = (*a)->next;
	}
	*a = tmp;
}

int	ft_find_chunk(t_list **a, int chunk)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->chunk == chunk || tmp->chunk == chunk + 1)
			i = 1;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_chunking(t_list **a)
{
	t_list	*tmp;
	int		c_size;

	tmp = *a;
	c_size = ft_set_chunk_size(ft_lstsize(*a),
			ft_set_chunk_number(ft_lstsize(*a)));
	ft_set_chunk_value(a, c_size);
}
