/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:36:43 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/28 17:18:52 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_digit(char **av, int flag)
{
	int	i;
	int	j;

	i = flag;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if ((av[i][j]) >= '0' && (av[i][j]) <= '9')
				j++;
			else
				ft_error();
		}
		i++;
		j = 0;
	}
}

void	ft_check_dubles(t_list **stack, int ac)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ac == 1)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				ft_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
