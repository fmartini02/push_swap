/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfication.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:59:35 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/23 16:27:11 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_splitfication(char *s, t_list **stack_a, int ac)
{
	t_list	*t;
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(s, ' ');
	ft_check_digit(tmp, 0);
	while (tmp[i])
	{
		t = ft_lstnew(ft_atoi(tmp[i++]));
		ft_lstadd_back(stack_a, t);
	}
	ft_check_dubles(stack_a, ac);
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
