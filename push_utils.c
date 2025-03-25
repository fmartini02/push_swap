/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:38 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/25 15:22:58 by francema         ###   ########.fr       */
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
	write(1, "Error:\nwrong FUNCTION inputs\n", 29);
	ft_free_stack(a, b);
	exit(0);
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
