/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:35:46 by francema          #+#    #+#             */
/*   Updated: 2025/04/17 15:48:07 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a)
		tmp = *a;
	while (tmp)
	{
		if (tmp->error == 1)
			return (1);
		tmp = tmp->next;
	}
	if (*b)
		tmp = *b;
	while (tmp)
	{
		if (tmp->error == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_format_utils(t_list **a, t_list **b, char **op_s)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	ft_free_stack(a, b);
	i = 0;
	while (op_s[i])
	{
		free(op_s[i]);
		i++;
	}
	free(op_s);
	exit(1);
}

void	check_format(t_list **a, t_list **b, char **op_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (op_s[i])
	{
		while (ft_isalpha(op_s[i][j]))
			j++;
		if (op_s[i][j] && op_s[i][j] != '\n')
			check_format_utils(a, b, op_s);
		if (!op_s[i][j])
			return ;
		j = 0;
		i++;
	}
}
