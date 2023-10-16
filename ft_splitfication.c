/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfication.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:59:35 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/13 16:54:29 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_splitfication(char *s, t_list **stack_a, int ac)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(s, ' ');
	ft_check_digit(tmp);
	while (tmp[i])
		ft_lstadd_front(stack_a, ft_lstnew(ft_atoi(tmp[i++])));
	ft_check_dubles(stack_a, ac);
}
