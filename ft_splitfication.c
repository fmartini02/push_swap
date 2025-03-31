/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfication.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:59:35 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/31 13:59:27 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	check_and_add_int(char **tmp, t_list **a, t_list **b, int flag)
{
	long int	n;
	t_list		*t;
	int			i;

	i = 0;
	while (tmp[i])
	{
		n = ft_atoi_long(tmp[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			free_tmp(tmp);
			ft_error(a, b);
		}
		t = ft_lstnew(n, flag);
		ft_lstadd_back(a, t);
		i++;
	}
}

void	ft_splitfication(char *s, t_list **a, t_list **b, int flag)
{
	char	**tmp;

	if (ft_strlen(s) == 0)
	{
		write(2, "error\n", 6);
		exit(0);
	}
	tmp = ft_split(s, ' ');
	if (!*tmp)
	{
		free_tmp(tmp);
		ft_free_stack(a, b);
		exit(0);
	}
	if (ft_check_digit(tmp, 0))
	{
		free_tmp(tmp);
		ft_error(a, b);
	}
	check_and_add_int(tmp, a, b, flag);
	ft_check_dubles(a, b, tmp);
	free_tmp(tmp);
}
