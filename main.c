/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:57:38 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:26:59 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_build_stack(t_list **stack, char **arg, int ac)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = 0;
	tmp = ft_lstnew(ft_atoi(arg[i++]));
	ft_lstadd_back(stack, tmp);
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi(arg[i++]));
		ft_lstadd_back(stack, tmp);
	}
}

void	ft_sort_5(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		s;

	tmp = *a;
	while (ft_chunk_status(a, 0) == 1)
	{
		if (tmp->chunk == 0)
			ft_push("pb", b, a);
		else
			ft_rotate("ra", a, b);
		tmp = *a;
	}
	ft_sort_5_utils(a, b);
}

void	ft_sort_small(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*a);
	if (i == 1)
		return ;
	else if (i == 2)
	{
		if ((*a)->pos > (*a)->next->pos)
			ft_swap("sa", a, b);
	}
	else if (i == 3)
		ft_sort_3(a, b);
	else if (i <= 5)
		ft_sort_5(a, b);
}

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*stack_a;
	int		size;

	stack_b = NULL;
	stack_a = NULL;
	size = 0;
	if (ac > 2)
	{
		ft_check_digit(av, 1);
		ft_build_stack(&stack_a, av, ac);
		ft_check_dubles(&stack_a, ac);
	}
	else if (ac == 2)
	{
		ft_splitfication(av[1], &stack_a, ac);
	}
	else
		return (0);
	ft_set_position(&stack_a);
	ft_chunking(&stack_a, &stack_b);
	if (ft_lstsize(stack_a) <= 5)
		ft_sort_small(&stack_a, &stack_b);
	ft_sorting(&stack_a, &stack_b);
	ft_free_stack(&stack_a, &stack_b);
}
