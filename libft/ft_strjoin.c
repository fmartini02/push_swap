/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:06:45 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/27 16:05:28 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*res;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, lens1);
	ft_memcpy(&res[lens1], s2, lens2);
	res[lens1 + lens2] = '\0';
	free(s1);
	return (res);
}
