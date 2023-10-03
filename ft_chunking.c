/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:17:49 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/28 17:13:27 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_n_chunk(int size)
{
	int n_chunk;

	n_chunk = 0;
	if (size >= 100)
		n_chunk = 4;
	else if (size >= 500)
		n_chunk = 6;
	else
		n_chunk = 2;
	return (n_chunk);
}

int ft_put_size(int size, int n_chunk)
{
	int c_size;

	if(size % 2 == 0)
		c_size = size / n_chunk;
	else
		c_size = (size / n_chunk) + 1;
	return (c_size);
}

void ft_putin_chunk(t_list **a, int c_size, int n_chunk)
{
	t_list  *tmp;

	tmp = *a;
	while(tmp)
	{
		if(tmp->pos <= c_size)
			tmp->chunk = 1;
		else if (tmp->pos >= c_size && tmp->pos <= (c_size * 2))
			tmp->chunk = 2;
		else if(tmp->pos >= (c_size * 2) && tmp->pos <= (c_size * 3) && n_chunk >= 4) 
			tmp->chunk = 3;
		else if(tmp->pos >= (c_size *3) && tmp->pos <= (c_size * 4) && n_chunk >= 4)
			tmp->chunk = 4;
		else if (tmp->pos >= (c_size *4) && tmp->pos <= (c_size *5) && n_chunk >= 6)
			tmp->chunk = 5;
		else if (tmp->pos >= (c_size *5) && tmp->pos <= (c_size *6) && n_chunk >= 6)
			tmp->chunk = 6;
		//ft_printf("cont: %d\npos: %d\nchunk: %d\n\n\n",tmp->content, tmp->pos, tmp->chunk);
		tmp = tmp->next;
	}
	//ft_printf("size: %d\n", ft_lstsize(*a));
}

void    ft_chunking(t_list **a, t_list **b)
{
	t_list  *tmp;
	int size;
	int c_size;
	int n_c;

	tmp = *a;
	n_c = 1;
	size = ft_lstsize(*a);
	c_size = ft_put_size(size, ft_n_chunk(size));
	ft_putin_chunk(a, c_size, ft_n_chunk(size));
	// while (tmp)
	// {
	// 	if(tmp->chunk == n_c)
	// 		ft_push("pb", b, a);
	// 	else if (tmp->chunk == (n_c + 1))
	// 	{
	// 		ft_push("pb", b, a);
	// 		ft_rotate("rb", a, b);
	// 	}
	// 	tmp = tmp->next;
	// 	if(tmp == NULL)
	// 	{
	// 		if(n_c < ft_n_chunk(size))
	// 			n_c +=2;
	// 		else
	// 			return ;
	// 		tmp = *a;
	// 	}
	// }
}
