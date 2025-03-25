/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:22:14 by francema          #+#    #+#             */
/*   Updated: 2025/03/24 18:23:03 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_build_stack(t_list **stack, char **arg, int ac, int flag)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = 0;
	tmp = ft_lstnew(ft_atoi(arg[i++]), flag);
	if (!tmp)
		ft_error(stack, stack);
	ft_lstadd_back(stack, tmp);
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi(arg[i++]), flag);
		if (!tmp)
			ft_error(stack, stack);
		ft_lstadd_back(stack, tmp);
	}
}
