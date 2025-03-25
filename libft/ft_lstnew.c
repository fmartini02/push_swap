/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:16:45 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/24 18:57:32 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content, int flag)
{
	t_list	*memb;

	memb = malloc(sizeof(t_list));
	if (!memb)
		return (NULL);
	memb->content = content;
	memb->next = NULL;
	memb->chunk = 0;
	memb->pos = 0;
	memb->flag = flag;
	return (memb);
}
