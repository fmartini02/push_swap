/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:36:43 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/22 16:11:17 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_digit(char **av, int flag, t_list **a, t_list **b)
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
				return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}

void	ft_check_dubles(t_list **a, t_list **b, int ac)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ac == 1)
		return ;
	tmp = *a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				ft_error(a, b);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
