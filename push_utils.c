/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:38 by fmartini          #+#    #+#             */
/*   Updated: 2025/04/22 16:03:19 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list **a, t_list **b)
{
	if (!*a && !*b)
	{
		write(2, "Error\n", 7);
		exit(0);
	}
	if ((*a)->flag == 1)
		(write(2, "Error\n", 7));
	else
		write(2, "Error\n", 7);
	ft_free_stack(a, b);
	exit(0);
}

void	ft_ferror(t_list **a, t_list **b)
{
	write(1, "Error:\nOPERATION/S ON EMPTY STACK\n", 34);
	if (*a)
		(*a)->error = 1;
	else if (*b)
		(*b)->error = 1;
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->content);
		ft_printf("pos: %d\n", lst->pos);
		ft_printf("chunk: %d\n", lst->chunk);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	ft_lstremove_front(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
}

void	print_op(t_list **a, t_list **b, char *str)
{
	if (ft_strchr(str, 'a'))
	{
		if ((*a)->flag == 0)
			ft_printf("%s\n", str);
	}
	else if (ft_strchr(str, 'b'))
	{
		if ((*b)->flag == 0)
			ft_printf("%s\n", str);
	}
	else if (((*b) && (*b)->flag == 0) || ((*a) && (*a)->flag == 0))
		ft_printf("%s\n", str);
}
