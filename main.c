/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:57:38 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/27 11:39:41 by francema         ###   ########.fr       */
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
	int		buff;

	tmp = *a;
	buff = 0;
	while (tmp)
	{
		if (tmp->pos == 1 || tmp->pos == 2)
		{
			ft_push("pb", b, a);
			buff++;
		}
		else
			ft_rotate("ra", a, b);
		if (buff == 2)
		{
			ft_sorty(a, b);
			return ;
		}
		tmp = *a;
	}
}

void	ft_sort_small(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*a);
	if (i == 1)
		return ;
	if (ft_check_order_a(a) == 1)
		return ;
	else if (i == 2)
	{
		if ((*a)->pos > (*a)->next->pos)
			ft_swap("sa", a, b);
	}
	else if (i == 3)
		ft_sort_3(a, b);
	else if (i == 4)
		ft_sort_4(a, b);
	else if (i <= 5)
		ft_sort_5(a, b);
}

int	main(int ac, char **av)
{
	t_list	*b;
	t_list	*a;
	int		size;

	b = NULL;
	a = NULL;
	size = 0;
	if (ac > 2)
	{
		if (ft_check_digit(av, 1, &a, &b))
			ft_error(&a, &b);
		ft_build_stack(&a, av, ac);
		ft_check_dubles(&a, &b, ac);
	}
	else if (ac == 2)
		ft_splitfication(av[1], &a, &b, ac);
	else
		return (0);
	ft_set_position(&a);
	ft_chunking(&a, &b);
	if (ft_lstsize(a) <= 5)
		ft_sort_small(&a, &b);
	ft_sorting(&a, &b);
	ft_free_stack(&a, &b);
}
