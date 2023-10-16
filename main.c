/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:57:38 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/16 17:41:48 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_build_stack(t_list **stack, char **arg, int ac)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = 0;
	*stack = ft_lstnew(ft_atoi(arg[i++]));
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi(arg[i]));
		ft_lstadd_back(stack, tmp);
		i++;
	}
	return (*stack);
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
		ft_check_digit(av);
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
	ft_sorting(&stack_a, &stack_b);
}
