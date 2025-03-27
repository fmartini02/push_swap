/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:36:43 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/27 16:38:52 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order_a(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if ((tmp->next->pos - tmp->pos == 1) && tmp->next)
			tmp = tmp->next;
		else if ((tmp->next->pos - tmp->pos != 1) && tmp->next)
			return (0);
	}
	return (1);
}

int	ft_check_digit_utils(char **av, int i, int j)
{
	int	n;

	n = 0;
	while (av[i][j] && av[i][j] == ' ' )
		j++;
	if (av[i][j] && (av[i][j] == '-' || av[i][j] == '+'))
		j++;
	if (av[i][j] && ft_isdigit(av[i][j]))
		n = ft_atoi(&av[i][j]);
	while (av[i][j] && av[i][j] == '0')
		j++;
	if (n != 0)
		j += ft_num_len(n, 10);
	while (av[i][j] && av[i][j] == ' ')
		j++;
	if (av[i][j])
		return (1);
	return (0);
}

int	ft_check_digit(char **av, int flag)
{
	int	i;
	int	j;
	int	n_sign;

	i = flag;
	j = 0;
	n_sign = 0;
	while (av[i])
	{
		if (ft_check_digit_utils(av, i, j))
			return (1);
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

void	ft_check_dubles(t_list **a, t_list **b, char **t)
{
	t_list	*tmp;
	t_list	*tmp2;

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
