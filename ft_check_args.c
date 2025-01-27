/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:36:43 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/27 19:25:23 by francema         ###   ########.fr       */
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

void	check_limits(char **av, int flag, t_list **a, t_list **b)
{
	int	i;
	int	n;

	i = flag;
	n = 0;
	while (av[i])
		n = ft_atoi(av[i++]);
}

void	ft_check_dubles(t_list **a, t_list **b, int ac, char **t)
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
			{
				if (t)
					free_tmp(t);
				ft_error(a, b);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
