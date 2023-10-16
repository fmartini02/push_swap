/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:38 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/13 16:44:32 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error:\nwrong PROGRAM inputs\n", 28);
	exit(0);
}

void	ft_ferror(void)
{
	write(1, "Error:\nwrong FUNCTION inputs\n", 29);
	exit(0);
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->content);
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
