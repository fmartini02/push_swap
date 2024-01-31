/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfication.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:59:35 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/31 17:08:47 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_splitfication(char *s, t_list **a, t_list **b, int ac)
{
	t_list	*t;
	int		i;
	char	**tmp;

	i = 0;
	if (ft_strlen(s) == 0)
		exit(0);
	tmp = ft_split(s, ' ');
	ft_check_digit(tmp, 0, a, b);
	while (tmp[i])
	{
		t = ft_lstnew(ft_atoi(tmp[i++]));
		ft_lstadd_back(a, t);
	}
	ft_check_dubles(a, b, ac);
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
