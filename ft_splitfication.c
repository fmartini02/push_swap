/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfication.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:59:35 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/22 16:16:52 by francema         ###   ########.fr       */
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

void	ft_splitfication(char *s, t_list **a, t_list **b, int ac)
{
	t_list	*t;
	int		i;
	char	**tmp;

	i = 0;
	if (ft_strlen(s) == 0)
		exit(0);
	tmp = ft_split(s, ' ');
	if (ft_check_digit(tmp, 0, a, b))
	{
		free_tmp(tmp);
		ft_error(a, b);
	}
	while (tmp[i])
	{
		t = ft_lstnew(ft_atoi(tmp[i++]));
		ft_lstadd_back(a, t);
	}
	ft_check_dubles(a, b, ac);
	i = 0;
	free_tmp(tmp);
}
