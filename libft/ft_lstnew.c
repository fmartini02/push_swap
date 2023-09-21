/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:16:45 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/04 17:15:04 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	 *ft_lstnew(int content)
{
	t_list	*memb;

	memb = malloc(sizeof(t_list));
	if (!memb)
		return (NULL);
	memb->content = content;
	memb->next = NULL;
	return (memb);
}
